#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        int window = 2 * k + 1;
        if(window > n)return res;

        long long runningSum = 0;
        for(int i = 0; i < window; i++)
        {
            runningSum += nums[i];
        }

        for(int i = k; i + k < n; i++)
        {
            res[i] = runningSum / window;
            if(i + k == n - 1)break;
            runningSum -= nums[i - k];
            runningSum += nums[i + k + 1];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {7,4,3,9,1,8,5,2,6};
        int k = 3;
        std::vector<int> res = {-1,-1,-1,5,4,4,-1,-1,-1};
        assert(sol.getAverages(nums, k) == res);
    }
    return 0;
}