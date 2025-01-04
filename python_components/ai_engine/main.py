from flask import Flask, request, jsonify
from neural_network import NeuralNetwork
from data_processor import DataProcessor

app = Flask(__name__)
nn = NeuralNetwork()
dp = DataProcessor()

@app.route('/predict', methods=['POST'])
def predict():
    data = request.json.get('data')
    processed_data = dp.process(data)
    prediction = nn.predict(processed_data)
    return jsonify({'prediction': prediction})

@app.route('/train', methods=['POST'])
def train():
    training_data = request.json.get('data')
    dp.process(training_data)
    nn.train(training_data)
    return jsonify({'status': 'training completed'})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
