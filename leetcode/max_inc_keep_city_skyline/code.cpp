#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> row(n);
        std::vector<int> col(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                row[i] = std::max(row[i], grid[i][j]);
                col[i] = std::max(col[i], grid[j][i]);
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res += std::min(col[j], row[i]) - grid[i][j];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{3,0,8,4},{2,4,5,7},
                                              {9,2,6,3},{0,3,1,0}};
        int res = 35;
        assert(sol.maxIncreaseKeepingSkyline(grid) == res);
    }
    return 0;
}