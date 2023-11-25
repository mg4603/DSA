#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) 
    {
        int n = nums.size();

        int count1 = 0;
        int count2 = 0;

        int candidate1 = 0;
        int candidate2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(count1 == 0 && nums[i] != candidate2)
            {
                count1++;
                candidate1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != candidate1)
            {
                count2++;
                candidate2 = nums[i];
            }
            else if(candidate1 == nums[i])
            {
                count1++;
            }
            else if(candidate2 == nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == candidate1)
            {
                count1++;
            }
            else if(nums[i] == candidate2)
            {
                count2++;
            }
        }

        std::vector<int> res;
        if(count1 > n / 3)
        {
            res.push_back(candidate1);
        }
        if(count2  > n / 3)
        {
            res.push_back(candidate2);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,2,3};
        std::vector<int> res = {3};
        assert(sol.majorityElement(nums) == res);
    }
    {
        std::vector<int> nums = {1};
        std::vector<int> res = {1};
        assert(sol.majorityElement(nums) == res);
    }
    {
        std::vector<int> nums = {1,2};
        std::vector<int> res = {1,2};
        assert(sol.majorityElement(nums) == res);
    }
    return 0;
}