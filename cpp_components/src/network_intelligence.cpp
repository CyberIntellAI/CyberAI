#include "network_intelligence.h"
#include <algorithm>

NetworkIntelligence::NetworkIntelligence() {}

void NetworkIntelligence::analyzeTraffic(const std::vector<std::string>& data) {
    // Placeholder for traffic analysis
    for (const auto& packet : data) {
        if (packet.find("malware") != std::string::npos) {
            insights.push_back("Malware detected in packet: " + packet);
        }
    }
}

std::vector<std::string> NetworkIntelligence::getInsights() const {
    return insights;
}
