#include "quantum_resistant.h"
#include <random>
#include <algorithm>

QuantumResistant::QuantumResistant() {}

std::vector<uint8_t> QuantumResistant::generateKey() {
    std::vector<uint8_t> key(32);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    std::generate(key.begin(), key.end(), [&]() { return dis(gen); });
    return key;
}

std::string QuantumResistant::encrypt(const std::string& data, const std::vector<uint8_t>& key) {
    std::string encrypted = data;
    for (size_t i = 0; i < data.size(); ++i) {
        encrypted[i] = data[i] ^ key[i % key.size()];
    }
    return encrypted;
}

std::string QuantumResistant::decrypt(const std::string& encrypted_data, const std::vector<uint8_t>& key) {
    // XOR encryption is symmetric
    return encrypt(encrypted_data, key);
}
