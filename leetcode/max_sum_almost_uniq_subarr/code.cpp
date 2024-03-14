#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    long long maxSum(std::vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long sum = 0;
        std::unordered_map<int, int> freq;

        int j = 0;
        long long runningSum = 0;
        int distinct = 0;
        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            if(freq[nums[i]] == 0)distinct++;
            freq[nums[i]]++;
            if(i - j + 1 == k)
            {
                if(distinct >= m)
                {
                    sum = std::max(runningSum, sum);
                }
                runningSum -= nums[j];
                if(--freq[nums[j++]] == 0)distinct--;
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,6,7,3,1,7};
        int m = 3;
        int k = 4;
        int res = 18;
        assert(sol.maxSum(nums, m, k) == res);
    }
    return 0;
}