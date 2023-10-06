#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        std::unordered_set<int> num_st;
        for(int i = 0; i < nums.size(); i++)
        {
            if(num_st.find(nums[i]) != num_st.end())
            {
                return nums[i];
            }
            num_st.insert(nums[i]);
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,3};
        int res = 3;
        assert(sol.repeatedNTimes(nums) == res);
    }
    {
        std::vector<int> nums = {2,1,2,5,3,2};
        int res = 2;
        assert(sol.repeatedNTimes(nums) == res);
    }
    {
        std::vector<int> nums = {5,1,5,2,5,3,5,4};
        int res = 5;
        assert(sol.repeatedNTimes(nums) == res);
    }
    return 0;
}