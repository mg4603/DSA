#include <assert.h>
#include <iostream>

#include <set>
#include <string>
#include <vector>
#include <algorithm>

std::string vecToString(std::vector<int> vec)
{
    std::string res;
    for(int num: vec)
    {
        res += std::to_string(num);
        res += ' ';
    }
    if(res.back() == ' ')res.pop_back();
    return res;
}

std::string lemmings_battle(int B, const std::vector<int>& SG, const std::vector<int>& SB){
    std::vector<int> green(SG.begin(), SG.end());
    std::vector<int> blue(SB.begin(), SB.end());

    std::string res;

    while(green.size() && blue.size())
    {
        int battleFields(std::min(B, static_cast<int>(green.size())));
        battleFields = std::min(battleFields, static_cast<int>(blue.size()));

        std::sort(green.begin(), green.end(), std::greater<int>());
        std::sort(blue.begin(), blue.end(), std::greater<int>());

        for(int i(0); i < battleFields; i++)
        {
            if(green[i] > blue[i])
            {
                green[i] -= blue[i];
                blue[i] = 0;
            }
            else
            {
                blue[i] -= green[i];
                green[i] = 0;
            }
        }
        green.erase(std::remove(green.begin(), green.end(), 0), green.end());
        blue.erase(std::remove(blue.begin(), blue.end(), 0), blue.end());
    }

    if(green.size() > 0)
    {
        std::sort(green.begin(), green.end(), std::greater<int>());
        res = "Green wins: " + vecToString(green);
    }
    else if(blue.size() > 0)
    {
        std::sort(blue.begin(), blue.end(), std::greater<int>());
        res = "Blue wins: " + vecToString(blue);
    }
    else
    {
        res =  "Green and Blue died";
    }
    return res;
}

int main()
{
    assert(lemmings_battle(5, {10}, {10}) == "Green and Blue died");
    assert(lemmings_battle(2, {20,10}, {10,10,15}) == "Blue wins: 5");
    assert(lemmings_battle(3, {50,40,30,40,50}, {50,30,30,20,60}) == "Green wins: 10 10");
    assert(lemmings_battle(1, {20,30}, {15}) == "Green wins: 20 15");
}