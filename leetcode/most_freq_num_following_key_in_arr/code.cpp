#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    int mostFrequent(std::vector<int>& nums, int key) 
    {
        int res = 0;
        int largest_frequency = 0;
        std::unordered_map<int, int> mp;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == key)
            {
                int temp = ++mp[nums[i + 1]];
                if(temp > largest_frequency)
                {
                    largest_frequency = temp;
                    res = nums[i + 1];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,100,200,1,100};
        int key = 1;
        int res = 100;
        assert(sol.mostFrequent(nums, key) == res);
    }
    {
        std::vector<int> nums = {2,2,2,2,3};
        int key = 2;
        int res = 2;
        assert(sol.mostFrequent(nums, key) == res);
    }
    return 0;
}