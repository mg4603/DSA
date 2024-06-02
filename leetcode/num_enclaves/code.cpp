#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void dfs(std::vector<std::vector<int>> &grid, 
             int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i == n || 
            j == m || grid[i][j] == 0)return;

        grid[i][j] = 0;
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i, j + 1, n, m);

    }
public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        int n = grid.size(); 
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            dfs(grid, i, 0, n, m);
            dfs(grid, i, m - 1, n, m);
        }
        for(int i = 0; i < m; i++) {
            dfs(grid, 0, i, n, m);
            dfs(grid, n - 1, i, n, m);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res += grid[i][j];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>>  grid = {{0,0,0,0},{1,0,1,0},
                                               {0,1,1,0},{0,0,0,0}};
        int res = 3;
        assert(sol.numEnclaves(grid) == res);
    }
    return 0;
}