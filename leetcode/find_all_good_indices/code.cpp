#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> goodIndices(std::vector<int>& nums, int k) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        
        int n = nums.size();
        std::vector<int> prefix(n, 1);
        std::vector<int> suffix(n, 1);
        for(int i = 1; i < n; i++)
        {
            if(nums[i - 1] >= nums[i])
            {
                prefix[i] += prefix[i - 1];
            }
            if(nums[n - i] >= nums[n - i - 1])
            {
                suffix[n - i - 1] += suffix[n - i];
            }
        }
        
        std::vector<int> res;
        for(int i = k; i < n - k; i++)
        {
            if(prefix[i - 1] >= k && suffix[i + 1] >= k)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,1,1,1,3,4,1};
        int k = 2;
        std::vector<int> res = {2, 3};
        assert(sol.goodIndices(nums, k) == res);
    }
    return 0;
}