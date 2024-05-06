#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<int> res(n);
        int i = 0, j = 0, k = 0;
        while(i < n)
        {
            while(j < n && nums[j] < 0)j++;
            res[i++] = nums[j++];
            while(k < n && nums[k] > 0)k++;
            res[i++] = nums[k++];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,1,-2,-5,2,-4};
        std::vector<int> res = {3,-2,1,-5,2,-4};
        assert(sol.rearrangeArray(nums) == res);
    }
    return 0;
}