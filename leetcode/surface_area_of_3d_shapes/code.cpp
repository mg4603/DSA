#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int surfaceArea(std::vector<std::vector<int>>& grid) {
        std::ios_base::sync_with_stdio(0);
        int n = grid.size();

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] > 0)
                {
                    res += (grid[i][j] * 4) + 2;
                    if(i - 1 >= 0)
                    {
                        res -= std::min(grid[i][j], grid[i-1][j]);
                    }
                    if(j - 1 >= 0)
                    {
                        res -= std::min(grid[i][j], grid[i][j - 1]);
                    }
                    if(i + 1 < n)
                    {
                        res -= std::min(grid[i][j], grid[i + 1][j]);
                    }
                    if(j + 1 < n)
                    {
                        res -= std::min(grid[i][j], grid[i][j + 1]);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {
            {1,2},{3,4}
        };
        int res = 34;
        assert(sol.surfaceArea(grid) == res);
    }
    {
        std::vector<std::vector<int>> grid = {
            {1,1,1},{1,0,1},{1,1,1}
        };
        int res = 32;
        assert(sol.surfaceArea(grid) == res);
    }
    {
        std::vector<std::vector<int>> grid = {
            {2,2,2},{2,1,2},{2,2,2}
        };
        int res = 46;
        assert(sol.surfaceArea(grid) == res);
    }
    return 0;
}