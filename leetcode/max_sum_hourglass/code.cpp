#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int maxSum(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        int res = std::numeric_limits<int>::min();
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n - 2; i++)
        {
            for(int j = 0; j < m - 2; j++)
            {
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + 
                        grid[i + 1][j + 1] + 
                        grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                res = std::max(sum, res);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{6,2,1,3},
                                              {4,2,1,5},
                                              {9,2,8,7},
                                              {4,1,2,9}};

        int res = 30;
        assert(sol.maxSum(grid) == res);
    }
    return 0;
}