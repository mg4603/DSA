#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(
                    std::vector<std::vector<int>>& obstacle_grid) 
    {
        int n = obstacle_grid.size();
        int m = obstacle_grid[0].size();
        std::vector<std::vector<int>> mat(n, std::vector<int>(m, 0));
        mat[0][0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(obstacle_grid[i][j])
                {
                    mat[i][j] = 0;
                    continue;
                }
                if(i - 1 >= 0)
                {
                    mat[i][j] += mat[i - 1][j];
                }
                if(j - 1 >= 0)
                {
                    mat[i][j] += mat[i][j - 1];
                }
            }
        }
        return mat[n - 1][m - 1];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> obstacle_grid = 
                                        {{0,0,0},{0,1,0},{0,0,0}};
        int res = 2;
        assert(sol.uniquePathsWithObstacles(obstacle_grid) == res);
    }
    {
        std::vector<std::vector<int>> obstacle_grid = {{0,1},{0,0}};
        int res = 1;
        assert(sol.uniquePathsWithObstacles(obstacle_grid) == res);
    }
    return 0;
}