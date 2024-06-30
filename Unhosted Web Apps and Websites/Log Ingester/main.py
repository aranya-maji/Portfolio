from flask import Flask, request, render_template
from pymongo import MongoClient
import threading
import re

app_logs = Flask(__name__)
app_webpage = Flask(__name__)

client = MongoClient('localhost',27017)
db = client['logs']
collection = db['log_collection']

@app_logs.route('/ingest',methods = ['POST'])
def ingest():
    if(request.method == 'POST'):
        if(request.headers['Content-Type'] == 'application/json'):
            logs = request.json
            collection.insert_one(logs)
            return 'Logs ingested'
        else:
            return 'Unsupported media'
    else:
        return 'Method not allowed'

def run_app_logs():
    app_logs.run(port = 3000, debug = True)


@app_webpage.route('/')
def index():
    return render_template('index.html')

@app_webpage.route('/get_logs',methods = ['POST'])
def get_logs():
    if(request.method == 'POST'):
        query = {}
        selected = request.form.getlist('field')
        for i in selected:
            if(i == 'level'):
                value = request.form[i]
                query[i] = re.compile(value,re.IGNORECASE)
            elif(i == 'message'):
                value = request.form[i]
                query[i] = re.compile(value,re.IGNORECASE)
            elif(i == 'resourceId'):
                value = request.form[i]
                v = value.split(',')
                if(len(v) == 1):
                    query[i] = value
                else:
                    query[i] = {'$gte':min(v),'$lte':max(v)}
            elif(i == 'timestamp'):
                value = request.form[i]
                v = value.split(',')
                if(len(v) == 1):
                    query[i] = value
                else:
                    query[i] = {'$gte':min(v),'$lte':max(v)}
            elif(i == 'traceId'):
                value = request.form[i]
                v = value.split(',')
                if(len(v) == 1):
                    query[i] = value
                else:
                    query[i] = {'$gte':min(v),'$lte':max(v)}
            elif(i == 'spanId'):
                value = request.form[i]
                v = value.split(',')
                if(len(v) == 1):
                    query[i] = value
                else:
                    query[i] = {'$gte':min(v),'$lte':max(v)}
            elif(i == 'commit'):
                value = request.form[i]
                v = value.split(',')
                if(len(v) == 1):
                    query[i] = value
                else:
                    query[i] = {'$gte':min(v),'$lte':max(v)}
            elif(i == 'metadata'):
                value = request.form[i]
                v = value.split(',')
                if(len(v) == 1):
                    query[i] = value
                else:
                    query[i] = {'$gte':min(v),'$lte':max(v)}
        if(len(query) == 0):
            logs = list(collection.find())
        else:
            logs = list(collection.find(query))
        return render_template('result.html', logs=logs)
    else:
        return 'Method not allowed'

def run_app_webpage():
    app_webpage.run(port = 5000, debug = True)

if(__name__ == '__main__'):
    thread_logs = threading.Thread(target=app_logs.run, kwargs={'port': 3000, 'use_reloader': False})
    thread_logs.start()
    thread_webpage = threading.Thread(target=app_webpage.run, kwargs={'port': 5000, 'use_reloader': False})
    thread_webpage.start()

