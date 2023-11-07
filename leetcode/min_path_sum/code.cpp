#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 1; i < n; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }

        for(int j = 1; j < m; j++)
        {
            grid[0][j] += grid[0][j - 1];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[n - 1][m - 1];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
        int res = 7;
        assert(sol.minPathSum(grid) == res);
    }
    {
        std::vector<std::vector<int>> grid = {{1,2,3},{4,5,6}};
        int res = 12;
        assert(sol.minPathSum(grid) == res);
    }
    return 0;
}