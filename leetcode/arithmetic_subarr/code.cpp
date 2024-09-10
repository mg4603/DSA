#include <iostream>
#include <assert.h>

#include <vector>
#include <climits>

class Solution {
    bool isArithmetic(std::vector<int> &nums, int left, int right) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = left; i <= right; i++)
        {
            mini = std::min(mini, nums[i]);
            maxi = std::max(maxi, nums[i]);
        }

        if(mini == maxi)return true;

        int n = right - left + 1;
        if((maxi - mini) % (n - 1))return false;
        std::vector<int> present(n, false);
        int diff = (maxi - mini) / (n - 1);

        for(int i = left; i <= right; i++)
        {
            if((nums[i] - mini) % diff)return false;

            int idx = (nums[i] - mini) / diff;
            if(present[idx])return false;
            present[idx] = true;
        }
        return true;
    }
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, 
                                std::vector<int>& l, std::vector<int>& r) {
        std::ios::sync_with_stdio(0);
        int n = l.size();
        std::vector<bool> res(n, false);
        for(int i = 0; i < n; i++)
        {
            if(isArithmetic(nums, l[i], r[i]))res[i] = true;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,6,5,9,3,7};
        std::vector<int> l = {0,0,2};
        std::vector<int> r = {2,3,5};
        std::vector<bool> res = {true,false,true};
        assert(sol.checkArithmeticSubarrays(nums, l, r) == res);
    }
    return 0;
}