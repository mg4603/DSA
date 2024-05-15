#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    const std::vector<int> DIRECTIONS{0, 1, 0, -1, 0};
    int solve(std::vector<std::vector<int>> &grid, 
              int rows, int cols, int row, int col) {
        if(row < 0 || col < 0 || row == rows || 
            col == cols || grid[row][col] == 0)return 0;

        int originalVal = grid[row][col];
        grid[row][col] = 0;
        int maxGold = 0;
        for(int i = 0; i < 4; i++) {
            maxGold = std::max(maxGold, 
                            solve(grid, rows, cols, 
                                row + DIRECTIONS[i], 
                                col + DIRECTIONS[i + 1]));
        }
        grid[row][col] = originalVal;
        return maxGold + originalVal;
    }
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = std::max(res, solve(grid, n,
                                         m, i , j));        
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{0,6,0},
                                              {5,8,7},
                                              {0,9,0}};
        int res = 24;
        assert(sol.getMaximumGold(grid) == res);
    }
    return 0;
}