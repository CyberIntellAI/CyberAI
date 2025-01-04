#ifndef NETWORK_INTELLIGENCE_H
#define NETWORK_INTELLIGENCE_H

#include <string>
#include <vector>

class NetworkIntelligence {
public:
    NetworkIntelligence();
    void analyzeTraffic(const std::vector<std::string>& data);
    std::vector<std::string> getInsights() const;
private:
    std::vector<std::string> insights;
};

#endif // NETWORK_INTELLIGENCE_H
