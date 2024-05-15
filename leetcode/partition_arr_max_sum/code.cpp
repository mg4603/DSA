#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxSumAfterPartitioning(std::vector<int>& arr, 
                                    int K) {
        int n = arr.size();
        std::vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++) {
            int curr = 0; int best = 0;
            for(int k = 1; k <= K && i - k >= 0; k++) {
                curr = std::max(curr, arr[i - k]);
                best = std::max(best, dp[i - k] + (curr * k));
            }
            dp[i] = best;
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,15,7,9,2,5,10};
        int k = 3;
        int res = 84;
        assert(sol.maxSumAfterPartitioning(arr, k) == res);
    }
    return 0;
}