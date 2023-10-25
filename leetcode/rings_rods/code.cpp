#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int countPoints(std::string rings) {
        std::vector<std::vector<int>> rods(10, std::vector<int>(3, 0));
        std::unordered_map<char, int> color_mp{{'R', 0}, {'G', 1}, {'B', 2}};

        for(int i = 0; i < rings.length(); i += 2)
        {
            char color = rings[i];
            int rod = (rings[i + 1] - '0');
            rods[rod][color_mp[color]]++;
        }
        int res = 0;
        for(int i = 0; i < 10; i++)
        {
            res++;
            for(int j = 0; j < 3; j++)
            {
                if(rods[i][j] < 1)
                {
                    res--;
                    break;
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
        std::string rings = "B0B6G0R6R0R6G9";
        int res = 1;
        assert(sol.countPoints(rings) == res);
    }
    {
        std::string rings = "B0R0G0R9R0B0G0";
        int res = 1;
        assert(sol.countPoints(rings) == res);
    }
    {
        std::string rings = "G4";
        int res = 0;
        assert(sol.countPoints(rings) == res);
    }
    return 0;
}