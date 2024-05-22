#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int dfs(std::vector<std::vector<int>> &grid, 
            int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || 
            grid[i][j] == 0)return 0;

        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j, n, m) +
            dfs(grid, i + 1, j, n, m) +
            dfs(grid, i, j - 1, n, m) + 
            dfs(grid, i, j + 1, n, m);
    }
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0)continue;
                res = std::max(res, dfs(grid, i, j, n, m));
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{0,0,0,0,0,0,0,0}};
        int res = 0;
        assert(sol.maxAreaOfIsland(grid) == res);
    }
    return 0;
}