#include <iostream>
#include <assert.h>

#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::stack<int> st;
        std::vector<int> res(n, -1);

        for(int i = 2 * n - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            if(!st.empty() && i < n)
            {
                   res[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,1};
        std::vector<int> res = {2,-1,2};
        assert(sol.nextGreaterElements(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4,3};
        std::vector<int> res = {2,3,4,-1,4};
        assert(sol.nextGreaterElements(nums) == res);
    }
    return 0;
}