#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int fillCups(std::vector<int>& amount) {
        int res = 0;
        while(std::accumulate(amount.begin(), amount.end(), 0)> 0)
        {
            std::sort(amount.begin(), amount.end());
            if(amount[1] > 0 && amount[2] > 0)
            {
                res++;
                amount[1]--;
                amount[2]--;
            }
            else if(amount[2] > 0)
            {
                res++;
                amount[2]--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> amount = {1,4,2};
        int res = 4;
        assert(sol.fillCups(amount) == res);
    }
    {
        std::vector<int> amount = {5,4,4};
        int res = 7;
        assert(sol.fillCups(amount) == res);
    }
    {
        std::vector<int> amount = {5,0,0};
        int res = 5;
        assert(sol.fillCups(amount) == res);
    }
    return 0;
}