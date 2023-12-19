#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
    bool helper(std::vector<int> &matchsticks, 
                std::vector<int> &sides, 
                int i, int side)
    {
        if(i == matchsticks.size())
        {
            return true;
        }

        for(int j = 0; j < 4; j++)
        {
            if(sides[j] + matchsticks[i] <= side)
            {
                sides[j] += matchsticks[i];
                if(helper(matchsticks, sides, i + 1, side))
                {
                    return true;
                }
                sides[j] -= matchsticks[i];
            }
        }
        return false;
    }
public:
    bool makesquare(std::vector<int>& matchsticks) 
    {
        int total_len = std::accumulate(matchsticks.begin(), 
                                        matchsticks.end(), 0);
        if(total_len / 4.0 != total_len / 4)
        {
            return false;
        }
        int side = total_len / 4;
        
        std::sort(matchsticks.begin(), 
                  matchsticks.end(), 
                  std::greater<int>());

        std::vector<int> sides(4, 0);

        return helper(matchsticks, sides, 0, side);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> matchsticks = {1,1,2,2,2};
        bool res = true;
        assert(sol.makesquare(matchsticks) == res);
    }
    {
        std::vector<int> matchsticks = {3,3,3,3,4};
        bool res = false;
        assert(sol.makesquare(matchsticks) == res);
    }
    return 0;
}