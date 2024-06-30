#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    long long beautifulSubarrays(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        std::unordered_map<int, long long> mp;
        mp[0] = 1;
        long long res = 0LL;
        for(int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] ^ nums[i - 1];
            if(mp.count(prefix[i]) && mp[prefix[i]])
            {
                res += mp[prefix[i]];
            }
            mp[prefix[i]]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,3,1,2,4};
        int res = 2;
        assert(sol.beautifulSubarrays(nums) == res);
    }
    return 0;
}