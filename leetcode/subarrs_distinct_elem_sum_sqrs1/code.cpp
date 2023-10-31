#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) 
    {
        int n = nums.size();
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            std::unordered_set<int> st;
            for(int k = i; k < n; k++)
            {
                st.insert(nums[k]);
                int temp = st.size();
                res += temp * temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,1};
        int res = 15;
        assert(sol.sumCounts(nums) == res);
    }
    {
        std::vector<int> nums = {1,1};
        int res = 3;
        assert(sol.sumCounts(nums) == res);
    }
    return 0;
}