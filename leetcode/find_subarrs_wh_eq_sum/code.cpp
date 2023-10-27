#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool findSubarrays(std::vector<int>& nums) 
    {
        std::unordered_set<int> st;
        int n = nums.size();

        for(int i = 1; i < n; i++)
        {
            int temp = nums[i - 1] + nums[i];
            if(st.count(temp))
            {
                return true;
            }    
            st.insert(temp);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,2,4};
        bool res = true;
        assert(sol.findSubarrays(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4,5};
        bool res = false;
        assert(sol.findSubarrays(nums) == res);
    }
    {
        std::vector<int> nums = {0,0,0};
        bool res = true;
        assert(sol.findSubarrays(nums) == res);
    }
    return 0;
}