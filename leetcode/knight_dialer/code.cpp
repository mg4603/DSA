#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    const int mod = 1e9 + 7;
    const std::vector<std::vector<int>> jumps = {
        {4, 6},
        {8, 6},
        {7, 9},
        {4, 8},
        {3, 9, 0}, 
        {},
        {1, 7, 0},
        {2, 6}, 
        {1, 3}, 
        {4, 2}
    };
    int helper(int n, int square, 
            std::vector<std::vector<int>> &memo) {
        if(n == 0)return 1;
        if(memo[n][square])return memo[n][square];
        int res = 0;
        for(const int &next: jumps[square]) {
            res = (res + helper(n - 1, next, memo)) % mod;
        }
        memo[n][square] = res;
        return res;
    }
public:
    int knightDialer(int n) {
        std::ios::sync_with_stdio(0);
        std::vector<std::vector<int>> memo(n + 1, 
                            std::vector<int>(10, 0));

        int res = 0;
        for(int i = 0; i < 10; i++) {
            res = (res + helper(n - 1, i, memo)) % mod;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 1, res = 10;
        assert(sol.knightDialer(n) == res);
    }
    return 0;
}