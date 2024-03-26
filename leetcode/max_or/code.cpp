#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    long long maximumOr(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> prefix(n + 1, 0);
        std::vector<long long> suffix(n + 1, 0);

        
        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] | nums[i];
            suffix[n - i - 1] = suffix[n - i] | nums[n - i - 1];
        }

        long long res = 0LL;
        long long p = 1 << k;

        for(int i = 0; i < n; i++)
        {
            res = std::max(res, 
                        static_cast<long long>(suffix[i + 1] | 
                                    prefix[i] | (nums[i] * p)));
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {12,9};
        int k = 1;
        int res = 30;
        assert(sol.maximumOr(nums, k) == res);
    }
    return 0;
}