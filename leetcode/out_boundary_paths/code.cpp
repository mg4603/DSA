#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int mod = 1e9 + 7;

    int helper(int m, int n, int N, int r, int c, 
                std::vector<std::vector<std::vector<int>>> &table){
        if(r == m || c == n || r < 0 || c < 0)return 1;
        if(N == 0)return 0;

        if(table[r][c][N] != -1)return table[r][c][N];

        table[r][c][N] = (
            (helper(m, n, N - 1, r - 1, c, table) + 
             helper(m, n, N - 1, r + 1, c, table)) % mod + 
            (helper(m, n, N - 1, r, c - 1, table) +
             helper(m, n, N - 1, r, c + 1, table)) % mod
            ) % mod;
        return table[r][c][N];
    }
public:
    int findPaths(int m, int n, int maxMove, int r, int c) 
    {
        if(maxMove == 0)
        {
            return 0;
        }
        std::vector<std::vector<std::vector<int>>> table(m, 
                    std::vector<std::vector<int>>(n, 
                        std::vector<int>(maxMove + 1, -1)));

        return helper(m, n, maxMove, r, c, table);
    }
};

int main()
{
    Solution sol;
    {
        int m = 2;
        int n = 2;
        int maxMove = 2;
        int startRow = 0;
        int startColumn = 0;
        int res = 6;
        assert(sol.findPaths(m, n, maxMove, startRow, startColumn) 
                == res);
    }
    {
        int m = 1;
        int n = 3;
        int maxMove = 3;
        int startRow = 0;
        int startColumn = 1;
        int res = 12;
        assert(sol.findPaths(m, n, maxMove, startRow, startColumn) 
                == res);
    }
    return 0;
}