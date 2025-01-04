use tokio::net::TcpListener;
use tokio::prelude::*;
use std::sync::Arc;
use rust_components::blockchain::Blockchain;

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let blockchain = Arc::new(Blockchain::new());
    let addr = "127.0.0.1:8080".parse()?;
    let listener = TcpListener::bind(addr).await?;
    println!("Blockchain node running on {}", addr);

    loop {
        let (socket, _) = listener.accept().await?;
        let blockchain = Arc::clone(&blockchain);
        tokio::spawn(async move {
            if let Err(e) = handle_connection(socket, blockchain).await {
                eprintln!("Failed to handle connection: {}", e);
            }
        });
    }
}

async fn handle_connection(mut socket: tokio::net::TcpStream, blockchain: Arc<Blockchain>) -> Result<(), Box<dyn std::error::Error>> {
    let mut buf = [0; 1024];
    let n = socket.read(&mut buf).await?;
    let request = String::from_utf8_lossy(&buf[..n]);
    println!("Received request: {}", request);

    let response = blockchain.process_request(request.to_string()).await;
    socket.write_all(response.as_bytes()).await?;
    Ok(())
}

