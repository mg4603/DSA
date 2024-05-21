#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
        int res = grid[0][0] <= k ? 1 : 0;
        if(res == 0)return res;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 1; i < n; i++)
        {
            grid[i][0] += grid[i - 1][0];
            if(grid[i][0] <= k)res++;
        }

        for(int j = 1; j < m; j++)
        {
            grid[0][j] += grid[0][j - 1];
            if(grid[0][j] <= k)res++;
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1];
                grid[i][j] -= grid[i - 1][j - 1];
                if(grid[i][j] <= k)res++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{7,6,3},
                                              {6,6,1}};
        int k = 18;
        int res = 4;
        assert(sol.countSubmatrices(grid, k) == res);
    }
    return 0;
}