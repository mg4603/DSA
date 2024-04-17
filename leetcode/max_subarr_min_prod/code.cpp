#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    const int mod = 1e9+7;
public:
    int maxSumMinProduct(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<long long> prefix(n + 1);

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long long res = 0LL;
        std::vector<int> st;
        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && (i == nums.size() || 
                            nums[st.back()] > nums[i]))
            {
                int j = st.back();
                st.pop_back();
                res = std::max(res, nums[j] * 
                            (prefix[i] - 
                             prefix[st.empty() ? 0 : st.back() + 1]));
            }

            st.push_back(i);
        }

        return res % mod;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,2};
        int res = 14;
        assert(sol.maxSumMinProduct(nums) == res);
    }
    return 0;
}