import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np

class NeuralNetworkModel(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super(NeuralNetworkModel, self).__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(hidden_size, output_size)
    
    def forward(self, x):
        out = self.fc1(x)
        out = self.relu(out)
        out = self.fc2(out)
        return out

class NeuralNetwork:
    def __init__(self):
        self.model = NeuralNetworkModel(input_size=10, hidden_size=50, output_size=1)
        self.criterion = nn.MSELoss()
        self.optimizer = optim.Adam(self.model.parameters(), lr=0.001)
    
    def predict(self, data):
        self.model.eval()
        with torch.no_grad():
            inputs = torch.tensor(data, dtype=torch.float32)
            outputs = self.model(inputs)
        return outputs.numpy().tolist()
    
    def train(self, training_data):
        self.model.train()
        inputs = torch.tensor(training_data['inputs'], dtype=torch.float32)
        targets = torch.tensor(training_data['targets'], dtype=torch.float32)
        
        self.optimizer.zero_grad()
        outputs = self.model(inputs)
        loss = self.criterion(outputs, targets)
        loss.backward()
        self.optimizer.step()
