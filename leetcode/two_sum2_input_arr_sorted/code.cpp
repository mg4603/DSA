#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;    

        while(l < r)
        {
            if(nums[l] + nums[r] == target)
            {
                return {l + 1, r + 1};
            }
            if(nums[l] + nums[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> numbers = {2,7,11,15};
        int target = 9;
        std::vector<int> res = {1,2};
        assert(sol.twoSum(numbers, target) == res);
    }
    {
        std::vector<int> numbers = {2,3,4};
        int target = 6;
        std::vector<int> res = {1,3};
        assert(sol.twoSum(numbers, target) == res);
    }
    {
        std::vector<int> numbers = {-1,0};
        int target = -1;
        std::vector<int> res = {1,2};
        assert(sol.twoSum(numbers, target) == res);
    }
    return 0;
}