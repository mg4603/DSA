#include <iostream>
#include <assert.h>

#include <map>

class Solution {
    const int mod = 1e9+7;
    int helper(int n, int k, int target, 
            std::map<std::pair<int, int>, int> &memo) {
        if(target == 0 && n == 0)return 1;
        if(n == 0 || target == 0)return 0;
        if(memo.count({n, target}))return memo[{n, target}];
        
        int res = 0;
        for(int i = 1; i <= k; i++) {
            res = ((res % mod) + 
                    (helper(n - 1, k, target - i, memo) % 
                    mod)) % mod;
        }

        memo[{n, target}] = res;
        return memo[{n, target}];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        std::ios::sync_with_stdio(0);
        std::map<std::pair<int, int>, int> memo;
        return helper(n, k, target, memo);
    }
};

int main()
{
    Solution sol;
    {
        int n = 1, k = 6, target = 3;
        int res = 1;
        assert(sol.numRollsToTarget(n, k, target) == res);
    }
    return 0;
}