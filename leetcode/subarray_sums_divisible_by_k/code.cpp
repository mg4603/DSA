#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int prefix = 0;
        std::unordered_map<int, int> freq;
        freq[prefix] = 1;

        for(int i = 0; i < n; i++)
        {
            prefix += (nums[i] % k);

            prefix %= k;
            if(prefix < 0)
            {
                prefix += k;
            }
            res += freq[prefix];
            freq[prefix]++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,5,0,-2,-3,1};
        int k = 5;
        int res = 7;
        assert(sol.subarraysDivByK(nums, k) == res);
    }
    return 0;
}