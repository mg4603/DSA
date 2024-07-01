#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countInterestingSubarrays(std::vector<int>& nums, 
                                        int mod, int k) {
        int n = nums.size();
        long long res = 0;
        std::unordered_map<int, int> freq;
        int cnt = 0;
        freq[cnt] = 1;

        for(int i = 0; i < n; i++)
        {
            cnt += (nums[i] % mod == k ? 1 : 0);
            cnt %= mod;
            res += freq[(cnt - k + mod) % mod];
            freq[cnt]++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,2,4};
        int modulo = 2; 
        int k = 1;
        int res = 3;
        assert(sol.countInterestingSubarrays(nums, modulo, k) == res);
    }
    return 0;
}