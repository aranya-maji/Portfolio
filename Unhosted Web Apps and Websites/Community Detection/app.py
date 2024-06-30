from flask import Flask, request, render_template, redirect, url_for
import pandas as pd
from io import StringIO
import networkx as nx
import community as community_louvain
import random
import plotly.graph_objects as go
import plotly.express as px

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload():
    if 'csvfile' not in request.files:
        return "No file part"

    file = request.files['csvfile']

    if file.filename == '':
        return "No selected file"

    if file:
        v = request.form["nField"]
        if(v == "0"):
            csv_data = file.read()
            df = pd.read_csv(StringIO(csv_data.decode('utf-8')))
            G = nx.from_pandas_edgelist(df, 'source', 'target')

            partition = community_louvain.best_partition(G)

            community_colors = {}
            for community in set(partition.values()):
                community_colors[community] = f'#{random.randint(0, 0xFFFFFF):06x}'


            for node, community in partition.items():
                G.nodes[node]['community'] = community


            pos = nx.spring_layout(G)


            edge_x = []
            edge_y = []
            for edge in G.edges():
                x0, y0 = pos[edge[0]]
                x1, y1 = pos[edge[1]]
                edge_x.extend([x0, x1, None])
                edge_y.extend([y0, y1, None])


            edge_trace = go.Scatter(
                x=edge_x,
                y=edge_y,
                line=dict(width=0.5, color='#888'),
                hoverinfo='none',
                mode='lines',
            )


            node_trace = []
            for community, color in community_colors.items():
                nodes_in_community = [node for node, comm in partition.items() if comm == community]
                x_community = [pos[node][0] for node in nodes_in_community]
                y_community = [pos[node][1] for node in nodes_in_community]
                
                trace = go.Scatter(
                    x=x_community,
                    y=y_community,
                    mode='markers',
                    marker=dict(size=10, color=color),
                    name=f'Community {community}',
                    hoverinfo='text',
                    text=[f'Node: {node}<br>Community: {community}' for node in nodes_in_community],
                )
                node_trace.append(trace)


            fig = go.Figure()
            fig.add_trace(edge_trace)
            for trace in node_trace:
                fig.add_trace(trace)


            fig.update_layout(
                title='Graph with Louvain Community Detection',
                showlegend=True,
                hovermode='closest',
            )


            fig.show()


        elif(v == "1"):
            csv_data = file.read()
            df = pd.read_csv(StringIO(csv_data.decode('utf-8')))
            G = nx.Graph()

            G.add_edges_from(df[['source', 'target']].values)

            def girvan_newman(G):
                if G.number_of_edges() == 0:
                    return []
                comp = nx.algorithms.community.girvan_newman(G)
                return tuple(sorted(c) for c in next(comp))

            optimal_communities = girvan_newman(G)
            for i in range(0,len(optimal_communities)):
                print(optimal_communities)
            node_data = []
            for i, community in enumerate(optimal_communities):
                for node in community:
                    node_attributes = df[df['source'] == node]
                    if not node_attributes.empty:
                        attributes_dict = node_attributes.iloc[0].to_dict()
                        attributes_text = '<br>'.join([f'{key}: {value}' for key, value in attributes_dict.items()])
                    else:
                        attributes_text = 'No attributes available'
                    
                    infected_count = len(df[df['source'] == node])
                    
                    attributes_text += f'<br>Affected: {infected_count} times'
                    
                    node_data.append({'Node': node, 'Community': i, 'Attributes': attributes_text})

            node_df = pd.DataFrame(node_data)

            layout = nx.kamada_kawai_layout(G)

            edges = G.edges()
            edge_x = []
            edge_y = []
            for edge in edges:
                x0, y0 = layout[edge[0]]
                x1, y1 = layout[edge[1]]
                edge_x.append(x0)
                edge_x.append(x1)
                edge_x.append(None)
                edge_y.append(y0)
                edge_y.append(y1)
                edge_y.append(None)

            edge_trace = go.Scatter(
                x=edge_x, y=edge_y,
                line=dict(width=0.5, color='#888'),
                hoverinfo='none',
                mode='lines')

            node_x = []
            node_y = []
            node_text = []
            for node in G.nodes():
                x, y = layout[node]
                degree = G.degree[node]
                infected_count = len(df[df['source'] == node])
                node_text.append(f"Source: {node}<br>Connections: {degree}<br>Affected: {infected_count} times")
                node_x.append(x)
                node_y.append(y)

            traces = []
            for community_id in node_df['Community'].unique():
                community_nodes = node_df[node_df['Community'] == community_id]
                community_x = community_nodes.apply(lambda row: node_x[row.name], axis=1)
                community_y = community_nodes.apply(lambda row: node_y[row.name], axis=1)
                trace = go.Scatter(
                    x=community_x, y=community_y,
                    marker=dict(
                        colorscale='Viridis',
                        size=10,
                        color=community_id,  # Assign a unique color for each community
                        showscale=False,  # Prevent the color scale from appearing
                        symbol='circle',
                        line=dict(width=1, color='black')
                    ),
                    mode='markers',
                    hoverinfo='text',
                    text=node_text,
                    name=f'Community {community_id}',  # Assign a name for the legend
                )
                traces.append(trace)

            fig = go.Figure(data=[edge_trace,*traces],
                         layout=go.Layout(
                            showlegend=True,
                            hovermode='closest',
                            margin=dict(b=0,l=0,r=0,t=0),
                            xaxis=dict(showgrid=False, zeroline=False, showticklabels=False),
                            yaxis=dict(showgrid=False, zeroline=False, showticklabels=False),
                            legend=dict(traceorder='normal')
                            )
                            )

            fig.show()

            print("Optimal Number of Communities:", len(optimal_communities))

        elif(v == "2"):
            csv_data = file.read()
            df = pd.read_csv(StringIO(csv_data.decode('utf-8')))
            
            G = nx.from_pandas_edgelist(df, 'source', 'target')

            communities = nx.algorithms.community.greedy_modularity_communities(G)

            node_community = {}
            for idx, comm in enumerate(communities):
                for node in comm:
                    node_community[node] = idx

            for node, comm_id in node_community.items():
                G.nodes[node]['community'] = comm_id

            pos = nx.spring_layout(G)

            edge_x = []
            edge_y = []
            for edge in G.edges():
                x0, y0 = pos[edge[0]]
                x1, y1 = pos[edge[1]]
                edge_x.extend([x0, x1, None])
                edge_y.extend([y0, y1, None])

            edge_trace = go.Scatter(
                x=edge_x,
                y=edge_y,
                line=dict(width=0.5, color='grey'),
                hoverinfo='none',
                mode='lines')

            node_x = []
            node_y = []
            node_text = []
            node_communities = list(node_community.values())
            node_data = []
            for i, community in enumerate(communities):
                for node in community:
                    node_attributes = df[df['source'] == node]
                    if not node_attributes.empty:
                        attributes_dict = node_attributes.iloc[0].to_dict()
                        attributes_text = '<br>'.join([f'{key}: {value}' for key, value in attributes_dict.items()])
                    else:
                        attributes_text = 'No attributes available'
                    
                    infected_count = len(df[df['source'] == node])
                    
                    attributes_text += f'<br>Affected: {infected_count} times'
                    
                    node_data.append({'Node': node, 'Community': i, 'Attributes': attributes_text})
            node_df = pd.DataFrame(node_data)
            for node in G.nodes():
                x, y = pos[node]
                degree = G.degree[node]
                infected_count = len(df[df['source'] == node])
                node_text.append(f"Source: {node}<br>Connections: {degree}<br>Affected: {infected_count} times")
                node_x.append(x)
                node_y.append(y)
            traces = []
            for community_id in node_df['Community'].unique():
                community_nodes = node_df[node_df['Community'] == community_id]
                community_x = community_nodes.apply(lambda row: node_x[row.name], axis=1)
                community_y = community_nodes.apply(lambda row: node_y[row.name], axis=1)
                trace = go.Scatter(
                    x=community_x, y=community_y,
                    marker=dict(
                        colorscale='Rainbow',
                        size=10,
                        color=community_id,  # Assign a unique color for each community
                        showscale=False,  # Prevent the color scale from appearing
                        symbol='circle',
                        line=dict(width=1, color='black')
                    ),
                    mode='markers',
                    hoverinfo='text',
                    text=node_text,
                    name=f'Community {community_id}',  # Assign a name for the legend
                )
                traces.append(trace)

            fig = go.Figure(data=[edge_trace,*traces],
                            layout=go.Layout(
                                title='Community Detection using Modularity Optimization',
                                titlefont_size=16,
                                showlegend=True,
                                hovermode='closest',
                                margin=dict(b=20, l=5, r=5, t=40),
                                annotations=[dict(
                                    text="",
                                    showarrow=False,
                                    xref="paper", yref="paper",
                                    x=0.005, y=-0.002)],
                                xaxis=dict(showgrid=False, zeroline=False, showticklabels=False),
                                yaxis=dict(showgrid=False, zeroline=False, showticklabels=False),
                                legend=dict(traceorder='normal')
                            ))

            fig.show()


        elif(v == "3"):
            csv_data = file.read()
            df = pd.read_csv(StringIO(csv_data.decode('utf-8')))

            G = nx.from_pandas_edgelist(df, 'source', 'target')

            communities = list(nx.algorithms.community.label_propagation.label_propagation_communities(G))

            node_community = {}
            for idx, community in enumerate(communities):
                for node in community:
                    node_community[node] = idx

            nx.set_node_attributes(G, node_community, 'community')

            pos = nx.spring_layout(G)

            node_data = pd.DataFrame(list(G.nodes(data=True)), columns=['node', 'data'])
            node_data['x'] = [pos[node][0] for node in G.nodes()]
            node_data['y'] = [pos[node][1] for node in G.nodes()]

            node_data['community'] = node_data['data'].apply(lambda x: x['community'])

            fig = px.scatter(node_data, x='x', y='y', color='community', hover_data=['node', 'community'],
                             title='Community Detection using Label Propagation')

            fig.update_traces(marker=dict(size=12))
            fig.update_layout(showlegend=False)

            fig.update_traces(hovertemplate='Node: %{customdata[0]}<br>Community: %{customdata[1]}')

            fig.show()


    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(host='127.0.0.1', port=5002, debug=True)
