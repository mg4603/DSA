#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int sum = std::accumulate(nums.begin(), 
                        nums.end(), 0);
        sum -= x;

        if(sum < 0)return -1;

        int res = -1;
        int runningSum = 0;
        int j = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            while(runningSum > sum)
            {
                runningSum -= nums[j++];
            }
            if(runningSum == sum)
            {
                res = std::max(res, i - j + 1);
            }
        }

        return res == -1 ? res : n - res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,4,2,3};
        int x = 5;
        int res = 2;
        assert(sol.minOperations(nums, x) == res);
    }
    return 0;
}