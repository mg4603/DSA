#include <iostream>
#include <assert.h>

#include <unordered_set>
#include <vector>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) 
    {
        std::unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)continue;
            st.insert(nums[i]);
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,5,0,3,5};
        int res = 3;
        assert(sol.minimumOperations(nums) == res);
    }
    {
        std::vector<int> nums = {0};
        int res = 0;
        assert(sol.minimumOperations(nums) == res);
    }
    return 0;
}