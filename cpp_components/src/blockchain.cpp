#include "blockchain.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

Blockchain::Blockchain() {
    // Create genesis block
    Block genesis;
    genesis.index = 0;
    genesis.timestamp = "2025-01-04T00:00:00Z";
    genesis.data = "Genesis Block";
    genesis.previous_hash = "0";
    genesis.hash = calculateHash(genesis.index, genesis.timestamp, genesis.data, genesis.previous_hash);
    chain.push_back(genesis);
}

void Blockchain::addBlock(const std::string& data) {
    Block last = chain.back();
    Block new_block;
    new_block.index = last.index + 1;
    // Get current timestamp
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(gmtime(&now_time_t), "%FT%TZ");
    new_block.timestamp = ss.str();
    new_block.data = data;
    new_block.previous_hash = last.hash;
    new_block.hash = calculateHash(new_block.index, new_block.timestamp, new_block.data, new_block.previous_hash);
    chain.push_back(new_block);
}

std::vector<Block> Blockchain::getChain() const {
    return chain;
}

std::string Blockchain::calculateHash(int index, const std::string& timestamp, const std::string& data, const std::string& previous_hash) {
    std::string input = std::to_string(index) + timestamp + data + previous_hash;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    return ss.str();
}
