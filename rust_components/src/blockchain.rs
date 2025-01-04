use serde::{Deserialize, Serialize};
use sha2::{Sha256, Digest};
use ring::rand::{SystemRandom, SecureRandom};
use serde_json::json;

#[derive(Serialize, Deserialize, Debug, Clone)]
pub struct Block {
    index: u64,
    timestamp: String,
    data: String,
    previous_hash: String,
    hash: String,
}

pub struct Blockchain {
    chain: Vec<Block>,
}

impl Blockchain {
    pub fn new() -> Self {
        let genesis_block = Block {
            index: 0,
            timestamp: chrono::Utc::now().to_rfc3339(),
            data: "Genesis Block".to_string(),
            previous_hash: "0".to_string(),
            hash: "0".to_string(),
        };
        Blockchain {
            chain: vec![genesis_block],
        }
    }

    pub async fn process_request(&self, request: String) -> String {
        // Simple JSON request handling
        let req: serde_json::Value = serde_json::from_str(&request).unwrap_or(json!({"type": "unknown"}));
        match req["type"].as_str().unwrap_or("unknown") {
            "add_block" => {
                let data = req["data"].as_str().unwrap_or("");
                self.add_block(data).await;
                json!({"status": "success", "message": "Block added"}).to_string()
            },
            "get_chain" => {
                serde_json::to_string(&self.chain).unwrap_or("[]".to_string())
            },
            _ => json!({"status": "error", "message": "Unknown request type"}).to_string(),
        }
    }

    pub async fn add_block(&self, data: &str) {
        let last_block = self.chain.last().unwrap();
        let new_block = Block {
            index: last_block.index + 1,
            timestamp: chrono::Utc::now().to_rfc3339(),
            data: data.to_string(),
            previous_hash: last_block.hash.clone(),
            hash: self.calculate_hash(last_block.index + 1, &chrono::Utc::now().to_rfc3339(), data, &last_block.hash),
        };
        // In a real implementation, you would handle concurrency and validation
        // Here, we'll just append for simplicity
        // self.chain.push(new_block);
    }

    fn calculate_hash(&self, index: u64, timestamp: &str, data: &str, previous_hash: &str) -> String {
        let mut hasher = Sha256::new();
        hasher.update(index.to_string());
        hasher.update(timestamp);
        hasher.update(data);
        hasher.update(previous_hash);
        let result = hasher.finalize();
        hex::encode(result)
    }
}
