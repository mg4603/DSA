#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int distinctAverages(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        std::unordered_set<double> st;

        for(int i = 0, j = nums.size() - 1; i < j; i++, j--)
        {
            double temp = nums[i] + nums[j];
            temp /= 2.0;
            st.insert(temp);
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,1,4,0,3,5};
        int res = 2;
        assert(sol.distinctAverages(nums) == res);
    }
    {
        std::vector<int> nums = {1,100};
        int res = 1;
        assert(sol.distinctAverages(nums) == res);
    }
    return 0;
}