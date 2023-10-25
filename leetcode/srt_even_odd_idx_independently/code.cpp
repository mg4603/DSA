#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortEvenOdd(std::vector<int>& nums) 
    {
        std::vector<int> odds;
        std::vector<int> evens;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i % 2 == 0)
            {
                evens.push_back(nums[i]);
            }
            else
            {
                odds.push_back(nums[i]);
            }
        }
        std::sort(odds.begin(), odds.end(), std::greater<int>());
        std::sort(evens.begin(), evens.end());
        int i = 0;
        int even_ptr = 0;
        int odd_ptr = 0;
        while(i < nums.size() && 
              even_ptr < evens.size() && 
              odd_ptr < odds.size())
        {
            nums[i++] = evens[even_ptr++];
            nums[i++] = odds[odd_ptr++];
        }
        while(even_ptr < evens.size())
        {
            nums[i++] = evens[even_ptr++];
        }
        while(odd_ptr < odds.size())
        {
            nums[i++] = odds[odd_ptr++];
        }

        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,1,2,3};
        std::vector<int> res = {2,3,4,1};
        assert(sol.sortEvenOdd(nums) == res);
    }
    {
        std::vector<int> nums = {2,1};
        std::vector<int> res = {2,1};
        assert(sol.sortEvenOdd(nums) == res);
    }
    return 0;
}