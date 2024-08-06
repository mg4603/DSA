#include <iostream>
#include <assert.h>

#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        
        long long res = 0ll;
        int n = nums.size();
        std::stack<int> st;

        for(int i = 0; i <= n; i++) {
            while(!st.empty() && nums[st.top()] > 
                    (i == n ? LLONG_MIN : nums[i])) {
                int j = st.top(); st.pop();
                int k = !st.empty() ? st.top(): -1;
                res -= (1LL * nums[j] * (i - j) * (j - k));
            }
            st.push(i);
        }

        st = std::stack<int>();
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && nums[st.top()] < 
                    (i == n ? LLONG_MAX : nums[i])) {
                int j = st.top(); st.pop();
                int k = !st.empty() ? st.top(): -1;
                res += (1LL * nums[j] * (i - j) * (j - k));
            }
            st.push(i);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        int res = 4;
        assert(sol.subArrayRanges(nums) == res);
    }
    return 0;
}