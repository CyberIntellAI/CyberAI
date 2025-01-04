# CyberAI API Documentation

## Overview

CyberAI provides a suite of APIs to interact with its AI engines, blockchain nodes, and network intelligence modules. This documentation outlines the available endpoints, their usage, and expected responses.

## Endpoints

### 1. AI Engine

#### a. `/predict`

- **Method:** POST
- **Description:** Sends data to the AI engine for prediction.
- **Request Body:**
    ```json
    {
        "data": [/* Array of numerical data */]
    }
    ```
- **Response:**
    ```json
    {
        "prediction": /* Prediction result */
    }
    ```

#### b. `/train`

- **Method:** POST
- **Description:** Trains the AI model with provided data.
- **Request Body:**
    ```json
    {
        "data": {
            "inputs": [/* Array of input data */],
            "targets": [/* Array of target data */]
        }
    }
    ```
- **Response:**
    ```json
    {
        "status": "training completed"
    }
    ```

### 2. Blockchain

#### a. `/add_block`

- **Method:** POST
- **Description:** Adds a new block to the blockchain.
- **Request Body:**
    ```json
    {
        "type": "add_block",
        "data": "Block data"
    }
    ```
- **Response:**
    ```json
    {
        "status": "success",
        "message": "Block added"
    }
    ```

#### b. `/get_chain`

- **Method:** GET
- **Description:** Retrieves the entire blockchain.
- **Response:**
    ```json
    [
        {
            "index": 0,
            "timestamp": "2025-01-04T00:00:00Z",
            "data": "Genesis Block",
            "previous_hash": "0",
            "hash": "..."
        },
        // More blocks...
    ]
    ```

### 3. Network Intelligence

#### a. `/analyze`

- **Method:** POST
- **Description:** Analyzes network traffic data.
- **Request Body:**
    ```json
    {
        "data": ["packet1", "packet2", "..."]
    }
    ```
- **Response:**
    ```json
    {
        "insights": ["Insight 1", "Insight 2", "..."]
    }
    ```

## Authentication

*(Detail any authentication mechanisms if applicable.)*

## Error Handling

All error responses follow the structure:
```json
{
    "status": "error",
    "message": "Error description"
}
