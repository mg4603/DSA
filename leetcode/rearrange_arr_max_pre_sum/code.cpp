#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxScore(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int res = 0;
        long long prefix = 0LL;
        for(int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];
            if(prefix <= 0)break;
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,-1,0,1,-3,3,-3};
        int res = 6;
        assert(sol.maxScore(nums) == res);
    }
    return 0;
}