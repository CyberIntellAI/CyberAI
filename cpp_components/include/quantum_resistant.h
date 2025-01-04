#ifndef QUANTUM_RESISTANT_H
#define QUANTUM_RESISTANT_H

#include <string>
#include <vector>

class QuantumResistant {
public:
    QuantumResistant();
    std::vector<uint8_t> generateKey();
    std::string encrypt(const std::string& data, const std::vector<uint8_t>& key);
    std::string decrypt(const std::string& encrypted_data, const std::vector<uint8_t>& key);
};

#endif // QUANTUM_RESISTANT_H
