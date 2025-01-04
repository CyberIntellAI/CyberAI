import numpy as np
import pandas as pd

class DataProcessor:
    def __init__(self):
        pass
    
    def process(self, data):
        df = pd.DataFrame(data)
        normalized = (df - df.mean()) / df.std()
        return normalized.values.tolist()
