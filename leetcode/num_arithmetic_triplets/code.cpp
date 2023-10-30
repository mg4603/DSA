#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    int arithmeticTriplets(std::vector<int>& nums, int diff) 
    {
        std::unordered_set<int> st;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(st.count(nums[i] + diff) && st.count(nums[i] + 2 * diff))
            {
                res++;        
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,4,6,7,10};
        int diff = 3;
        int res = 2;
        assert(sol.arithmeticTriplets(nums, diff) == res);
    }
    {
        std::vector<int> nums = {4,5,6,7,8,9};
        int diff = 2;
        int res = 2;
        assert(sol.arithmeticTriplets(nums, diff) == res);
    }
    return 0;
}