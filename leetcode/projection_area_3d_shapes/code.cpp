#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int projectionArea(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // area of x-axis aligned projection
        int x(0);
        // area of y-axis aligned projection
        int y(0);
        // area of z-axis aligned projection
        int z(0);
        x = n * m;
        for(int i(0); i < n; i++)
        {
            y += *std::max_element(grid[i].begin(), grid[i].end());
        }
        for(int i(0); i < m; i++)
        {
            int temp(0);
            for(int j(0); j < n; j++)
            {
                if(grid[j][i] > temp)
                {
                    temp = grid[j][i];
                }    
                if(grid[j][i] == 0)
                {
                    x--;
                }            
            }
            z += temp;
        }
        return x + y + z;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {
                {1,2}, {3,4}
            };
        int output = 17;
        assert(sol.projectionArea(grid) == output);
    }
    {
        std::vector<std::vector<int>> grid = {
                {2}
            };
        int output = 5;
        assert(sol.projectionArea(grid) == output);
    }
    {
        std::vector<std::vector<int>> grid = {
                {1,0},{0,2}
            };
        int output = 8;
        assert(sol.projectionArea(grid) == output);
    }
    return 0;
}