#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    long long largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<long long> prefix(n + 1, 0LL);

        long long res = 0LL;

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
            if(prefix[i] > nums[i] && i >= 2)
            {
                res = std::max(res, prefix[i + 1]);
            }
        }
        return res == 0 ? -1 : res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,5,5};
        int res = 15;
        assert(sol.largestPerimeter(nums) == res);
    }
    return 0;
}