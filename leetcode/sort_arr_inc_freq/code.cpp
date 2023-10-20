#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) 
    {
        std::vector<int> vec(201, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            vec[nums[i] + 100]++;
        }
        std::sort(nums.begin(), nums.end(), [&](int a, int b)
        {
            if(vec[a + 100] == vec[b + 100])
            {
                return a > b;
            }
            return vec[a + 100] < vec[b + 100];
        });
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,2,2,2,3};
        std::vector<int> res = {3,1,1,2,2,2};
        assert(sol.frequencySort(nums) == res);
    }
    {
        std::vector<int> nums = {2,3,1,3,2};
        std::vector<int> res = {1,3,3,2,2};
        assert(sol.frequencySort(nums) == res);
    }
    {
        std::vector<int> nums = {-1,1,-6,4,5,-6,1,4,1};
        std::vector<int> res = {5,-1,4,4,-6,-6,1,1,1};
        assert(sol.frequencySort(nums) == res);
    }
    return 0;
}