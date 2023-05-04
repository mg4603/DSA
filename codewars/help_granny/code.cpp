#include <assert.h>
#include <iostream>

#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <cmath>

typedef std::unordered_map<std::string, double> stringdblmap;

class Tour
{
public:
    static int tour(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, stringdblmap &h);
};

int Tour::tour(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, 
        stringdblmap &h)
{
    std::map<std::string, std::string> frTwnMp;
    for(auto ftwn: ftwns){
        frTwnMp[ftwn.at(0)] = ftwn.at(1);
    }

    double routeLen(0);
    std::string prevLoc;
    for(std::string fr: arrFriends)
    {
        if(prevLoc == "X0"){
            routeLen += h[frTwnMp[fr]];
        }
        else if (frTwnMp.count(fr) == 0)
        {
            continue;
        }
        else
        {
            routeLen += sqrt(pow(h[frTwnMp[fr]], 2) - pow(h[prevLoc], 2));
        }
        prevLoc = frTwnMp[fr];
    }
    routeLen += h[prevLoc];
    return routeLen;
}

void testequal(int ans, int sol) {
    assert(ans == sol);
}

void dotest(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, stringdblmap &h, int expected)
{
    testequal(Tour::tour(arrFriends, ftwns, h), expected);
}

int main()
{
    std::vector<std::string> friends1 = { "A1", "A2", "A3", "A4", "A5" };
    std::vector<std::vector<std::string>> fTowns1 = { {"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"} };
    stringdblmap distTable1 = { {"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0} };
    dotest(friends1, fTowns1, distTable1, 889);

    friends1 = { "A1", "A2", "A3", "A4", "A5" };
    fTowns1 = { {"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"}, {"A5", "X5"} };
    distTable1 = { {"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0}, {"X5", 320.0} };
    dotest(friends1, fTowns1, distTable1, 1020);

    return 0;
}
    

