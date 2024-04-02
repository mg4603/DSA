#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<long long> minOperations(std::vector<int>& nums, 
                                        std::vector<int>& q) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<long long> prefix(n + 1, 0LL);
        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = (prefix[i] + 1LL * nums[i]);
        }
        
        int m = q.size();
        std::vector<long long> res(m, 0LL);
        for(int i = 0; i < m; i++)
        {
            int mid = std::lower_bound(nums.begin(), 
                            nums.end(), q[i]) - nums.begin();

            res[i] = prefix[n] - 2 * prefix[mid] + 
                        1LL * (2 * mid - n) * q[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,1,6,8};
        std::vector<int> queries = {1,5};
        std::vector<long long> res = {14, 10};
        assert(sol.minOperations(nums, queries) == res);
    }
    return 0;
}