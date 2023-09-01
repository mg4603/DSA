#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int res(0);
        for(int i(0); i < grid.size(); i++)
        {
            for(int j(0); j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    res += 4;
                    if(i > 0 && grid[i - 1][j] == 1)
                    {
                        res -= 2;
                    }
                    if(j > 0 && grid[i][j - 1] == 1)
                    {
                        res -= 2;
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
        std::vector<std::vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
        assert(sol.islandPerimeter(grid) == 16);
    }
    {
        std::vector<std::vector<int>> grid = {{1}};
        assert(sol.islandPerimeter(grid) == 4);
    }
    {
        std::vector<std::vector<int>> grid = {{1, 0}};
        assert(sol.islandPerimeter(grid) == 4);
    }
    return 0;
}