#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int helper(std::vector<int> &prefix, int L, int M)
    {
        int res = 0;
        int maxL = 0;
        for(int i = L + M; i < prefix.size(); i++)
        {
            maxL = std::max(maxL, prefix[i - M] - 
                                    prefix[i - M - L]);

            res = std::max(res, maxL + prefix[i] - 
                                    prefix[i - M]);
        }
        return res;
    }
public:
    int maxSumTwoNoOverlap(std::vector<int>& nums, 
                            int L, int M) {
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        return std::max(helper(prefix, L, M), 
                        helper(prefix, M, L));
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,6,5,2,2,5,1,9,4};
        int firstLen = 1;
        int secondLen = 2;
        int res = 20;
        assert(sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) == res);
    }
    
    return 0;
}