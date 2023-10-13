#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(
                                    std::vector<std::vector<int>>& grid, 
                                    int k)
         {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> res = std::vector<std::vector<int>>(
                                            m, std::vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int new_r = (i + ((j + k) / n)) % m;
                int new_c = (j + k) % n;
                res[new_r][new_c] = grid[i][j];
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
            {1,2,3},{4,5,6},{7,8,9}
        };
        int k = 1;
        std::vector<std::vector<int>> res = {
            {9,1,2},{3,4,5},{6,7,8}
        };
        assert(sol.shiftGrid(grid, k) == res);
    }
    {
        std::vector<std::vector<int>> grid = {
            {3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}
        };
        int k = 4;
        std::vector<std::vector<int>> res = {
            {12,0,21,13},{3,8,1,9},{19,7,2,5},{4,6,11,10}
        };
        assert(sol.shiftGrid(grid, k) == res);
    }
    {
        std::vector<std::vector<int>> grid = {
            {1,2,3},{4,5,6},{7,8,9}
        };
        int k = 9;
        std::vector<std::vector<int>> res = {
            {1,2,3},{4,5,6},{7,8,9}
        };
        assert(sol.shiftGrid(grid, k) == res);
    }
    return 0;
}