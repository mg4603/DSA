#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, 
                                    int maximumBit) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        long long largest_num = 0LL;
        
        for(int i = 0; i < maximumBit; i++)
        {
            largest_num += std::pow(2, i);
        }
        
        std::vector<int> res(n, 0);
        long long xor_total = std::accumulate(nums.begin(), 
                                    nums.end(), 0LL, 
                                    [](long long a, int b){return a ^ b;});
        for(int i = 0; i < n; i++)
        {
            res[i] = xor_total ^ largest_num;
            xor_total ^= nums[n - i - 1];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,1,3};
        int maximumBit = 2;
        std::vector<int> res = {0,3,2,3};
        assert(sol.getMaximumXor(nums, maximumBit) == res);
    }
    return 0;
}