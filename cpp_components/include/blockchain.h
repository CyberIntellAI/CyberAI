#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <string>
#include <vector>

struct Block {
    int index;
    std::string timestamp;
    std::string data;
    std::string previous_hash;
    std::string hash;
};

class Blockchain {
public:
    Blockchain();
    void addBlock(const std::string& data);
    std::vector<Block> getChain() const;
private:
    std::vector<Block> chain;
    std::string calculateHash(int index, const std::string& timestamp, const std::string& data, const std::string& previous_hash);
};

#endif // BLOCKCHAIN_H
