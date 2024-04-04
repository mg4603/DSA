#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int waysToSplitArray(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        int n = nums.size();
        std::vector<long long> prefix(n, 0LL);
        
        for(int i = 0; i < n; i++)
        {
            prefix[i] += nums[i];
            if(i > 0)prefix[i] += prefix[i - 1];
        }

        for(int i = 0; i < n - 1; i++)
        {
            if(2 * prefix[i] >= prefix[n-1])
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums ={10,4,-8,7};
        int res = 2;
        assert(sol.waysToSplitArray(nums) == res);
    }
    return 0;
}