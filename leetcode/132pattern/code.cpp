#include <iostream>
#include <assert.h>

#include <vector>
#include <stack>
#include <limits>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::stack<std::pair<int, int>> st;
        int min_val = std::numeric_limits<int>::max();

        for(int i = 0; i < n; i++)
        {
            while(st.size() && st.top().first <= nums[i])
            {
                st.pop();
            }

            if(nums[i] < min_val)
            {
                min_val = nums[i];
            }

            if(st.size() && st.top().first > nums[i] && 
                nums[i] > st.top().second)
            {
                return true;
            }

            if(st.size() == 0 || st.top().first > nums[i])
            {
                st.push({nums[i], min_val});
            }

        }

        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4};
        bool res = false;
        assert(sol.find132pattern(nums) == res);
    }
    {
        std::vector<int> nums = {3,1,4,2};
        bool res = true;
        assert(sol.find132pattern(nums) == res);
    }
    {
        std::vector<int> nums = {-1,3,2,0};
        bool res = true;
        assert(sol.find132pattern(nums) == res);
    }
    return 0;
}