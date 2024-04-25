#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
    const int mod = 1e9+7;
public:
    int waysToSplit(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::partial_sum(nums.begin(), nums.end(), nums.begin());
        int n = nums.size();
        int j = 0;
        int k = 0;
        int res = 0;
        for(int i = 0; i < n - 2; i++)
        {
            j = std::max(i + 1, j);
            while( j < n - 1 && nums[j] < 2 * nums[i])j++;

            k = std::max(j, k);
            while(k < n - 1 && 
                    nums[k] - nums[i] <= nums[n - 1] - nums[k])k++;

            res = (res + k - j) % mod;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2,2,5,0};
        int res = 3;
        assert(sol.waysToSplit(nums) == res);
    }
    return 0;
}