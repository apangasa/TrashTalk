from flask import Flask, request, jsonify
from flask_cors import CORS
import json


app = Flask(__name__)
CORS(app)


@app.route('/', methods=['GET'])
def hello_world():
    return 'Up and running', 200

# /submit-voice?command={command}


@app.route('/submit-voice', methods=['GET'])
def submit_voice():
    args = request.args
    command = args.get('command')

    with open('./commands.data', 'a') as comm_file:
        comm_file.write(command)
    return jsonify(success=True), 200


if __name__ == '__main__':
    app.run()
