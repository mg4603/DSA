#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        
        std::unordered_map<int, int> freq;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            ++freq[nums[i]];
            while(freq[nums[i]] > k)
            {
                freq[nums[j++]]--;
            }
            res = std::max(res, i - j + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,1,2,3,1,2};
        int k = 2;
        int res = 6;
        assert(sol.maxSubarrayLength(nums, k) == res);
    }
    return 0;
}