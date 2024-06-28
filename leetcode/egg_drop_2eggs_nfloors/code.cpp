#include <iostream>
#include <assert.h>

#include <map>
#include <vector>

class Solution {
    int solve(int n, int k,  
            std::map<std::pair<int, int>, int> &memo) {
        if(k == 1 || n <= 1)return n;
        if(memo.count({n, k}))return memo[{n, k}];

        int min_attempts = n;
        for(int i = 1; i <= n; i++) {
            int attempts_i = std::max(solve(n - i, k, memo),
                            solve(i - 1, k - 1, memo)) + 1;
            min_attempts = std::min(min_attempts, attempts_i);
        }
        memo[{n, k}] = min_attempts;
        return min_attempts;
    }

    int solveK2(int n, std::vector<int> &memo) {
        if(memo[n] != 0)return memo[n];
        if(n <= 1)return n;

        int min_attempts = n;
        for(int i = 1; i <= n; i++) {
            int attempts_i = std::max(i - 1,  
                            solveK2(n - i, memo)) + 1;
            min_attempts = std::min(min_attempts, attempts_i);
        }
        memo[n] = min_attempts;
        return memo[n];
    }
public:
    int twoEggDrop(int n) {
        std::ios::sync_with_stdio(0);
        std::vector<int> memo(n+1, 0);
        return solveK2(n, memo);
    }
};

int main()
{
    Solution sol;
    {
        int n = 2, res = 2;
        assert(sol.twoEggDrop(n) == res);
    }
    return 0;
}