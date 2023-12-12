#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minMoves(std::vector<int>& nums) 
    {
        int res = 0;
        int min = *std::min_element(nums.begin(), nums.end());
        res = std::accumulate(nums.begin(), nums.end(), 0, 
                    [&](int a, int b){ return a + std::abs(min-b);});
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        int res = 3;
        assert(sol.minMoves(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1};
        int res = 0;
        assert(sol.minMoves(nums) == res);
    }
    return 0;
}