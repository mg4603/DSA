#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximumDifference(std::vector<int>& nums) 
    {
        int res = -1;
        int min_visited = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(min_visited < nums[i])
            {
                int temp = nums[i] - min_visited;
                if(temp > res)
                {
                    res = temp;
                }
            }
            if(nums[i] < min_visited)
            {
                min_visited = nums[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {7,1,5,4};
        int res = 4;
        assert(sol.maximumDifference(nums) == res);
    }
    {
        std::vector<int> nums = {9,4,3,2};
        int res = -1;
        assert(sol.maximumDifference(nums) == res);
    }
    {
        std::vector<int> nums = {1,5,2,10};
        int res = 9;
        assert(sol.maximumDifference(nums) == res);
    }
    return 0;
}