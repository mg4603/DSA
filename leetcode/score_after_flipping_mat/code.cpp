#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; ++i)
        {
            if(grid[i][0] == 1)continue;
            for(int j = 0; j < m; j++) {
                grid[i][j] ^= 1;
            }
        }

        int res = 0;
        for(int j = 0; j < m; j++) {
            int zeros = 0;
            int ones = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 1)ones++;
                else zeros++;
            }
            res *= 2;
            res += std::max(ones, zeros);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{0,0,1,1},
                                              {1,0,1,0},
                                              {1,1,0,0}};
        int res = 39;
        assert(sol.matrixScore(grid) == res);
    }
    return 0;
}