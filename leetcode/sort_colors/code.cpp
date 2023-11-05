#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<int> counts(3, 0);
        for(int i = 0; i < n; i++)
        {
            counts[nums[i]]++;
        }    

        int ptr = 0;
        for(int i = 0; i < 3; i++)
        {
            int j = 0;
            while(j++ < counts[i])
            {
                nums[ptr++] = i;
            }
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,0,2,1,1,0};
        std::vector<int> res = {0,0,1,1,2,2};
        sol.sortColors(nums);
        assert(nums == res);
    }
    {
        std::vector<int> nums = {2,0,1};
        std::vector<int> res = {0,1,2};
        sol.sortColors(nums);
        assert(nums == res);
    }
    return 0;
}