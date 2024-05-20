#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>
#include <map>
#include <numeric>

class UndergroundSystem {
    std::unordered_map<int, 
                    std::pair<std::string, int>> users;
    std::map<std::pair<std::string, std::string>, 
             std::vector<int>> avgTimes;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, std::string stationName, int t) {
        users[id] = {stationName, t};
    }
    
    void checkOut(int id, std::string stationName, int t) {
        avgTimes[{users[id].first, stationName}].push_back(
                                        t - users[id].second);
    }
    
    double getAverageTime(std::string startStation, 
                            std::string endStation) {
        std::vector<int> & vec = 
                    avgTimes[{startStation, endStation}];
        return std::accumulate(vec.begin(), 
                    vec.end(), 0.0) / vec.size();
    }
};

int main()
{
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);  
    undergroundSystem.checkOut(27, "Waterloo", 20);  
    undergroundSystem.checkOut(32, "Cambridge", 22); 
    assert(undergroundSystem.getAverageTime("Paradise", "Cambridge") == 14.00000);
    assert(undergroundSystem.getAverageTime("Leyton", "Waterloo") == 11.00000);
    undergroundSystem.checkIn(10, "Leyton", 24);
    assert(undergroundSystem.getAverageTime("Leyton", "Waterloo") == 11.00000);    
    undergroundSystem.checkOut(10, "Waterloo", 38);  
    assert(undergroundSystem.getAverageTime("Leyton", "Waterloo") == 12.00000);
    return 0;
}