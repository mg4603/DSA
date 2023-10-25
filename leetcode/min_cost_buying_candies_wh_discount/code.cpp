#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumCost(std::vector<int>& cost) 
    {
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        int res = 0;
        for(int i = 0; i < cost.size(); i+=3)
        {
            res += cost[i];
            if(i + 1 < cost.size())
            {
                res += cost[i + 1];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> cost = {1,2,3};
        int res = 5;
        assert(sol.minimumCost(cost) == res);
    }
    {
        std::vector<int> cost = {1,2,3};
        int res = 5;
        assert(sol.minimumCost(cost) == res);
    }
    {
        std::vector<int> cost = {1,2,3};
        int res = 5;
        assert(sol.minimumCost(cost) == res);
    }
    return 0;
}