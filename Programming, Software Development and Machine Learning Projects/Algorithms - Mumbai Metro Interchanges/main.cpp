#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include<map>
#include<queue>
#include<string>
#include<graphics.h>
using namespace std;


class  Graph_Map
{
public:

    class Station
    {
    public:
        map<string,int> nbrs;
        Station()
        {
            this->nbrs={};
        }
    };
    map<string, Station> vtces;

    Graph_Map()
    {
        this->vtces = {};
    }
    bool isPresent_Station(string vname)
    {
        if(vtces.find(vname)!=vtces.end())
            return true;
        else
            return false;
    }
    void createStation(string vname)
    {
        Station stn; //= new Station();//doubt/
        vtces.insert({vname, stn});
    }
    bool isPresent_Route(string vname1, string vname2)
    {
        Station stn1 = vtces[vname1];
        Station stn2 = vtces[vname2];

        if(vtces.find(vname1)==vtces.end() || vtces.find(vname2)==vtces.end() || stn1.nbrs.find(vname2)==stn1.nbrs.end())
        {
            return false;
        }

        return true;
    }
    void createRoute(string vname1, string vname2, int value)
    {
        Station &stn1 = vtces[vname1];
        Station &stn2 = vtces[vname2];

        if (vtces.find(vname1)==vtces.end() || vtces.find(vname2)==vtces.end() || stn1.nbrs.find(vname2) != stn1.nbrs.end())
        {
            return;
        }

        stn1.nbrs.insert({vname2, value});
        stn2.nbrs.insert({vname1, value});
    }

    vector<string> returnkeys()
    {
        vector<string>keys;
        for(auto i: vtces)
        {
            keys.push_back(i.first);
        }
        return keys;
    }

    void display_Map()
    {
        cout<<"\t Train Route Advisor";
        cout<<"\t------------------";
        cout<<"----------------------------------------------------\n";


        vector<string> keys;
        for (auto it : vtces)
        {
            keys.push_back(it.first);
        }
        for (int j=0; j<keys.size();j++)
        {
            string str = keys[j] + " =>\n";
            Station stn = vtces[keys[j]];
            vector<string> stnnbrs;
            for (auto it: stn.nbrs)
            {
                stnnbrs.push_back(it.first);
            }
            for (int i=0; i<stnnbrs.size(); i++)
            {
                str = str + "\t" + stnnbrs[i] + "\t";
                if (stnnbrs[i].length()<16)
                {
                    str = str + "\t";
                }
                if (stnnbrs[i].length()<8)
                {
                    str = str + "\t";
                }
                str = str + to_string(stn.nbrs[stnnbrs[i]]) + "\n";
            }
            cout<<str<<endl;
        }
        cout<<"\t------------------";
        cout<<"---------------------------------------------------\n";
    }
    void display_Stations()
    {
        cout<<"\n*************************\n";
        vector<string> keys;
        for (auto it : vtces)
        {
            keys.push_back(it.first);
        }
        int i=1;
        for(int j=0; j<keys.size(); j++)
        {
            cout<<i<<"  "<<keys[j]<<endl;
            i++;
        }
        cout<<"\n*************************\n";
    }
    bool isPath(string vname1, string vname2, map<string, bool> &processed)
    {
        // DIR EDGE
        if (isPresent_Route(vname1, vname2))
        {
            return true;
        }

        //MARK AS DONE
        processed.insert({vname1, true});
        cout<<endl;
        Station stn = vtces[vname1];
        vector<string> keys;
        for (auto it = stn.nbrs.begin(); it != stn.nbrs.end(); it++)
        {
            keys.push_back(it->first);
        }

        //TRAVERSE THE NBRS OF THE Station
        for (int i=0;i<keys.size();i++)
        {
            if (processed.find(keys[i])== processed.end())
            {
                if (isPath(keys[i], vname2, processed))
                {
                    return true;
                }
            }
        }
        return false;
    }

    struct pair
    {
        string vname;
        string psf;
        int min_dis;
        int min_time;
    };
    string get_Minimum_Distance(string src, string dst)
    {
        int min = INT_MAX;
        //int time = 0;
        string ans = "";
        map<string, bool> processed;
        vector<pair>stock;

        // create a new pair
        struct pair sp;
        sp.vname = src;
        sp.psf = src + ",";
        sp.min_dis = 0;
        sp.min_time = 0;


        stock.insert(stock.begin(),sp);

        // while stack is not empty keep on doing the work
        while (!stock.empty())
        {
            // remove a pair from stack
            pair rp = stock[0];
            stock.erase(stock.begin());


            if (processed.find(rp.vname) != processed.end())
            {
                continue;
            }

            // processed put
            processed.insert({rp.vname, true});

            //if there exists a direct edge b/w removed pair and destination Station
            if (rp.vname == dst)
            {
                int temp = rp.min_dis;
                if(temp<min)
                {
                    ans = rp.psf;
                    min = temp;
                }
                continue;
            }

            Station rpstn = vtces[rp.vname];
            vector<string> keys;
            for(auto i: rpstn.nbrs)
            {
                keys.push_back(i.first);
            }
            for(auto nbr : keys)
            {
                // process only unprocessed nbrs
                if (processed.find(nbr) == processed.end()) // != ya == doubt
                {

                    // make a new pair of nbr and put in queue
                    pair np;
                    np.vname = nbr;
                    np.psf = rp.psf + nbr + ",";
                    np.min_dis = rp.min_dis + rpstn.nbrs[nbr];

                    stock.insert(stock.begin(),np);
                }
            }
        }
        ans = ans + to_string(min);
        return ans;
    }




    string get_Minimum_Time(string src, string dst)
    {
        int min = INT_MAX;
        string ans = "";
        map<string, bool> processed;
        vector<pair> stock;

        // create a new pair
        pair sp;
        sp.vname = src;
        sp.psf = src + ",";
        sp.min_dis = 0;
        sp.min_time = 0;

        // put the new pair in queue
        stock.insert(stock.begin(), sp); //replacing addFirst

        while (!stock.empty())
        {
            pair rp = stock[0];
            stock.erase(stock.begin());
            if (processed.find(rp.vname) != processed.end())
            {
                continue;
            }

            // processed put
            processed.insert({rp.vname, true});

            //if there exists a direct edge b/w removed pair and destination Station
            if (rp.vname == dst)
            {
                int temp = rp.min_time;
                if(temp<min)
                {
                    ans = rp.psf;
                    min = temp;
                }
                continue;
            }

            Station rpstn = vtces[rp.vname];
            vector<string> keys;
            for(auto i: rpstn.nbrs)
            {
                keys.push_back(i.first);
            }
            for (string nbr : keys)
            {
                // process only unprocessed nbrs
                if (processed.find(nbr) == processed.end())
                {
                    struct pair np;
                    np.vname = nbr;
                    np.psf = rp.psf + nbr + ",";
                    np.min_time = rp.min_time + (rpstn.nbrs[nbr]*60)/40;
                    stock.insert(stock.begin(), np); //replacing addFirst
                }
            }
        }
        ans = ans + to_string(min);
        return ans;
    }


    class dijkstrapair
    {
    public:
        string vname;
        string psf;
        int cost;
    };


    int dijkstra(string src, string des)
    {
        int val =0;
        vector<string>ans;
        map<string, dijkstrapair> m;

        for(auto i: vtces)
        {
            string key = i.first;
            dijkstrapair np;
            np.vname = key;
            np.cost = INT_MAX;

            if(key == src)
            {
                np.cost = 0;
                np.psf = key;
            }

            m.insert({key,np});
        }

        while(true)
        {
            int mi = INT_MAX;
            dijkstrapair rp;
            for(auto i :m)
            {
                if(i.second.cost<mi)
                {
                    mi = i.second.cost;
                    rp = i.second;
                }
            }
            if(rp.vname==des)
            {
                val = rp.cost;
                break;
            }

            m.erase(rp.vname);

            ans.push_back(rp.vname);

            Station v = vtces[rp.vname];

            for(auto nbr: v.nbrs)
            {
                if(m.find(nbr.first)!=m.end())
                {
                    int oc = m[nbr.first].cost;

                    Station k = vtces[rp.vname];

                    int nc;

                    nc = rp.cost + k.nbrs[nbr.first];

                    if(nc < oc)
                    {
                        dijkstrapair &gp = m[nbr.first];
                        gp.psf = rp.psf + nbr.first;
                        gp.cost = nc;
                        m[nbr.first] = gp;
                    }
                }
            }
        }
        return val;
    }
};


vector<string> get_Path(string str)
{
    vector<string>arr;
    vector<string>res;
    int f=0,l=0;
    for(int i=0; i<str.length();i++)
    {
        if(str[i] == ',')
        {
            res.push_back(str.substr(l,i-l));
            l=i+1;
        }
    }
    res.push_back(str.substr(l,str.length()-l));
    cout<<endl;
    arr.push_back(res[0]);
    int count =0;
    for(int i=1;i<res.size()-1;i++)
    {
        int index = res[i].find_first_of("-");
        string s = res[i].substr(index+1);
        cout<<s<<endl;
        if(s.length()==2)
        {
            string prev = res[i-1].substr((res[i-1].find_first_of("-"))+1);
            string next = res[i+1].substr((res[i+1].find_first_of("-"))+1);

            if(prev == next)
            {

                arr.push_back(res[i]);

            }
            else
            {

                arr.push_back(res[i] + "==>" + res[i+1]);
                i++;
                count++;

            }
        }
        else
        {

            arr.push_back(res[i]);

        }
    }
    arr.push_back(to_string(count));
    arr.push_back(res[res.size()-1]);
    return arr;

}

void graph()
{
    initwindow(1500,900);
    setcolor(WHITE);
    settextstyle(8,0,3);
    outtextxy(1150,50,"LEGEND:-");
    settextstyle(8,0,2);
    MYSQL* con2;
    MYSQL_ROW row2;
    MYSQL_RES* res2;
    con2 = mysql_init(0);
    con2 = mysql_real_connect(con2,"localhost","root",NULL,"miniproject",0,NULL,0);
    if(con2)
    {
        int qstate = mysql_query(con2, "SELECT station_name, station_short_name FROM station ORDER BY station_name");
        if(!qstate)
        {
            int i = 0, j = 80;
            res2 = mysql_store_result(con2);
            while(row2 = mysql_fetch_row(res2))
            {
                i++;
                j = j + 20;
                string s1 = row2[0];
                string s2 = row2[1];
                string I = to_string(i);
                string x = I + "." + s1 + " " + "-" + " " + s2;
                char* c = const_cast<char*>(x.c_str());
                outtextxy(1000,j,c);
            }
        }
    }
    mysql_close(con2);
    setlinestyle(0,0,3);
    MYSQL* con3;
    MYSQL_ROW row3;
    MYSQL_RES* res3;
    con3 = mysql_init(0);
    con3 = mysql_real_connect(con3,"localhost","root",NULL,"miniproject",0,NULL,0);
    if(con3)
    {
        int qstate = mysql_query(con3, "SELECT c1.cir_x_axis, c1.cir_y_axis, c2.cir_x_axis, c2.cir_y_axis, r.colour FROM route as r, station as c1, station as c2 WHERE ((c1.station_name = r.station_one) AND (c2.station_name = r.station_two))");
        if(!qstate)
        {
            res3 = mysql_store_result(con3);
            while(row3 = mysql_fetch_row(res3))
            {
                int x1, y1, x2, y2, c;
                sscanf(row3[0], "%d", &x1);
                sscanf(row3[1], "%d", &y1);
                sscanf(row3[2], "%d", &x2);
                sscanf(row3[3], "%d", &y2);
                sscanf(row3[4], "%d", &c);
                setcolor(c);
                line(x1,y1,x2,y2);
            }
        }
    }
    mysql_close(con3);
    setlinestyle(0,0,1);
    setcolor(WHITE);
    settextstyle(8,0,1);

    MYSQL* con4;
    MYSQL_ROW row4;
    MYSQL_RES* res4;
    con4 = mysql_init(0);
    con4 = mysql_real_connect(con4,"localhost","root",NULL,"miniproject",0,NULL,0);
    if(con4)
    {
        int qstate = mysql_query(con4, "SELECT station_short_name, cir_x_axis, cir_y_axis, name_x_axis, name_y_axis FROM station");
        if(!qstate)
        {
            res4 = mysql_store_result(con4);
            while(row4 = mysql_fetch_row(res4))
            {
                int x1, y1, x2, y2;
                sscanf(row4[1], "%d", &x1);
                sscanf(row4[2], "%d", &y1);
                sscanf(row4[3], "%d", &x2);
                sscanf(row4[4], "%d", &y2);
                circle(x1,y1,20);
                outtextxy(x2,y2,row4[0]);
            }
        }
    }
    mysql_close(con4);
}

void create_train_map(Graph_Map *g)
{
    MYSQL* con;
    MYSQL_ROW row;
    MYSQL_RES* res;
    con = mysql_init(0);
    con = mysql_real_connect(con,"localhost","root",NULL,"miniproject",0,NULL,0);
    if(con)
    {
        int qstate = mysql_query(con, "SELECT station_name FROM station");
        if(!qstate)
        {
            res = mysql_store_result(con);
            while(row = mysql_fetch_row(res))
            {
                g->createStation(row[0]);
            }
        }
    }
    mysql_close(con);

    MYSQL* con1;
    MYSQL_ROW row1;
    MYSQL_RES* res1;
    con1 = mysql_init(0);
    con1 = mysql_real_connect(con1,"localhost","root",NULL,"miniproject",0,NULL,0);
    if(con1)
    {
        int qstate = mysql_query(con1, "SELECT station_one, station_two, weight FROM route");
        if(!qstate)
        {
            res1 = mysql_store_result(con1);
            while(row1 = mysql_fetch_row(res1))
            {
                int x;
                sscanf(row1[2], "%d", &x);

                g->createRoute(row1[0],row1[1],x);
            }
        }
    }
    mysql_close(con1);
}




int main()
{
    Graph_Map g;
    create_train_map(&g);

    graph();
    while(true)
    {
        cout<<"\t\t\t\t~~LIST OF ACTIONS~~\n\n"<<endl;
        cout<<"1. LIST ALL THE STATIONS IN THE MAP"<<endl;
        cout<<"2. SHOW THE TRAIN MAP"<<endl;
        cout<<"3. GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
        cout<<"4. GET SHORTEST TIME TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
        cout<<"5. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
        cout<<"6. GET SHORTEST PATH (TIME WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
        cout<<"7. GET FARE FOR JOURNEY FROM 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
        cout<<"8. EXIT THE MENU"<<endl;
        cout<<"\nENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 7) : ";
        int choice = -1;
        cin>>choice;
        cout<<"\n***********************************************************\n";
        if(choice == 8)
        {
            closegraph();
            exit(0);
        }
        switch(choice)
        {
            case 1:
                g.display_Stations();
                break;

            case 2:
                g.display_Map();
                break;

            case 3:
            {
                vector<string>keys = g.returnkeys();
                cout<<"\n1. TO ENTER SERIAL NO. OF STATIONS\n2. TO ENTER NAME OF STATIONS\n"<<endl;
                cout<<"ENTER YOUR CHOICE:"<<endl;
                int ch;
                cin>>ch;
                int j;

                string st1 = "", st2 = "";
                if(ch == 1)
                {
                    cout<<"ENTER SERIAL NO. 1:";
                    int in1;
                    cin>>in1;
                    cout<<"ENTER SERIAL NO. 2:";
                    int in2;
                    cin>>in2;
                    st1 = keys[in1-1];
                    st2 = keys[in2-1];
                }
                else if(ch == 2)
                {
                    cout<<"ENTER THE SOURCE STATION: "<<endl;
                    fflush(stdin);
                    getline(cin,st1);
                    cout<<"ENTER THE DESTINATION STATION: "<<endl;
                    fflush(stdin);
                    getline(cin,st2);
                }
                else
                {
                    cout<<"INVALID CHOICE"<<endl;
                    exit(0);
                }
                map<string, bool>processed;
                if(!g.isPresent_Station(st1) || !g.isPresent_Station(st2) || !g.isPath(st1, st2, processed))
                {
                    cout<<"THE INPUTS ARE INVALID"<<endl;
                }
                else
                {
                    cout<<"SHORTEST DISTANCE FROM "<<st1<<" TO "<<st2<<" IS "<<g.dijkstra(st1, st2)<<"KM\n"<<endl;
                }
                break;
            }

            case 4:
            {
                //assuming speed is 40km/hr
                string st1="",st2="";
                cout<<"ENTER THE SOURCE STATION: "<<endl;
                fflush(stdin);
                getline(cin,st1);
                cout<<"ENTER THE DESTINATION STATION: "<<endl;
                fflush(stdin);
                getline(cin,st2);
                map<string, bool>processed;
                if(!g.isPresent_Station(st1) || !g.isPresent_Station(st2) || !g.isPath(st1, st2, processed))
                {
                    cout<<"THE INPUTS ARE INVALID"<<endl;
                }
                else
                {
                    cout<<"SHORTEST TIME FROM "<<st1<<" TO "<<st2<<" IS "<<((g.dijkstra(st1, st2)*60)/40)+" MINUTES\n\n"<<endl;
                }
                break;
            }

            case 5:
            {
                cout<<"ENTER THE SOURCE STATION: "<<endl;
                fflush(stdin);
                string s1;
                getline(cin,s1);
                cout<<"ENTER THE DESTINATION STATION: "<<endl;
                fflush(stdin);
                string s2;
                getline(cin,s2);

                map<string, bool> processed2;
                if(!g.isPresent_Station(s1) || !g.isPresent_Station(s2) || !g.isPath(s1, s2, processed2))
                {
                    cout<<"THE INPUTS ARE INVALID"<<endl;
                }
                else
                {
                    vector<string> str = get_Path(g.get_Minimum_Distance(s1, s2));
                    int len = str.size();
                    cout<<"SOURCE STATION : "<<s1<<endl;
                    cout<<"DESTINATION STATION : "<<s2<<endl;
                    cout<<"DISTANCE : "<<str[len - 1]<<endl;
                    cout<<"~~~~~~~~~~~~~"<<endl;
                    cout<<"START ==> "<<str[0]<<endl;
                    for(int i=1; i<len-3; i++)
                    {
                        cout<<str[i]<<endl;
                    }
                    cout<<str[len - 3]<<"  ==>  END"<<endl;
                    cout<<"~~~~~~~~~~~~~"<<endl;
                }
                break;
            }

            case 6:
            {
                cout<<"ENTER THE SOURCE STATION: "<<endl;
                fflush(stdin);
                string ss1;
                getline(cin,ss1);
                cout<<"ENTER THE DESTINATION STATION: "<<endl;
                fflush(stdin);
                string ss2;
                getline(cin,ss2);

                map<string, bool> processed3;
                if(!g.isPresent_Station(ss1) || !g.isPresent_Station(ss2) || !g.isPath(ss1, ss2, processed3))
                {
                    cout<<"THE INPUTS ARE INVALID"<<endl;
                }
                else
                {
                    vector<string> str = get_Path(g.get_Minimum_Time(ss1, ss2));
                    int len = str.size();
                    cout<<"SOURCE STATION : "<<ss1<<endl;
                    cout<<"DESTINATION STATION : "<<ss2<<endl;
                    cout<<"TIME : "<<str[len - 1]<<" MINUTES"<<endl;
                    cout<<"NUMBER OF INTERCHANGES : "<<str[len - 2]<<endl;
                    cout<<"~~~~~~~~~~~~~"<<endl;
                    cout<<"START ==> "<<str[0]<<endl;
                    for(int i=1; i<len-3; i++)
                    {
                        cout<<str[i]<<endl;
                    }
                    cout<<str[len - 3]<<"  ==>  END"<<endl;
                    cout<<"~~~~~~~~~~~~~"<<endl;
                }
                break;
            }

            case 7:
            {
                cout<<"ENTER THE SOURCE STATION: "<<endl;
                fflush(stdin);
                string ss1;
                getline(cin,ss1);
                cout<<"ENTER THE DESTINATION STATION: "<<endl;
                fflush(stdin);
                string ss2;
                getline(cin,ss2);

                map<string, bool> processed3;
                if(!g.isPresent_Station(ss1) || !g.isPresent_Station(ss2) || !g.isPath(ss1, ss2, processed3))
                {
                    cout<<"THE INPUTS ARE INVALID"<<endl;
                }
                else
                {
                    //Assuming that per km the cost is fixed
                    //Assuming it to be 2 rupees per km
                    string str = g.get_Minimum_Distance(ss1, ss2);
                    vector<string>res;
                    int l=0;
                    for(int i=0; i<str.length();i++)
                    {
                        if(str[i] == ',')
                        {
                            res.push_back(str.substr(l,i-l));
                            l=i+1;
                        }
                    }
                    res.push_back(str.substr(l,str.length()-l));
                    int dis = stoi(res[res.size() - 1]);
                    int fare = dis * 2;
                    if(fare < 70)
                    {
                        fare = 70;
                    }
                    else if(fare > 200)
                    {
                        fare = 200;
                    }
                    cout<<"SOURCE STATION : "<<ss1<<endl;
                    cout<<"DESTINATION STATION : "<<ss2<<endl;
                    cout<<"FARE : "<<fare<<" RUPEES"<<endl;
                }
                break;
            }
            default:
                cout<<"Please enter a valid option! "<<endl;
                cout<<"The options you can choose are from 1 to 6. "<<endl;
         }
     }
}
