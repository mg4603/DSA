#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<long long> findPrefixScore(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> res(n, 0LL);

        int curr_max = 0;
        for(int i = 0; i < n; i++)
        {
            curr_max = std::max(curr_max, nums[i]);
            res[i] = curr_max + nums[i];
            if(i > 0)
            {
                res[i] += res[i - 1];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,7,5,10};
        std::vector<long long> res = {4,10,24,36,56};
        assert(sol.findPrefixScore(nums) == res);
    }
    return 0;
}