#include <iostream>
#include <assert.h>

#include <vector>
#include <bitset>

class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        for(int h(0); h < 12; h++)
        {
            for(int m(0); m < 60; m++)
            {
                if(std::bitset<10>(h << 6 | m).count() == turnedOn)
                {
                    res.push_back(
                        std::to_string(h) + ":" + 
                        (m < 10? ("0" + std::to_string(m)): std::to_string(m)));
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.readBinaryWatch(1) == std::vector<std::string>(
                {"0:01","0:02","0:04","0:08","0:16","0:32",
                "1:00","2:00","4:00","8:00"}));
        assert(sol.readBinaryWatch(9) == std::vector<std::string>({}));
    }
    return 0;
}