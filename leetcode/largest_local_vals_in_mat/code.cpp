#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(
                                    std::vector<std::vector<int>>& grid)
    {
        int n = grid.size();
        std::vector<std::vector<int>> res(n - 2, std::vector<int>(n - 2, 0));
        for(int i = 1; i < n - 1; i++)
        {
            for(int j = 1; j < n - 1; j++)
            {
                int temp = 0;
                for(int k = -1; k < 2; k++)
                {
                    for(int l = -1; l < 2; l++)
                    {
                        if(grid[i + k][j + l] > temp)
                        {
                            temp = grid[i + k][j + l];
                        }
                    }
                }
                res[i-1][j-1] = temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{9,9,8,1},
                                 {5,6,2,6},
                                 {8,2,6,4},
                                 {6,2,2,2},};
        std::vector<std::vector<int>> res = {{9,9},
                                {8,6},};
        assert(sol.largestLocal(grid) == res);
    }
    {
        std::vector<std::vector<int>> grid = {{1,1,1,1,1},
                                 {1,1,1,1,1},
                                 {1,1,2,1,1},
                                 {1,1,1,1,1},
                                 {1,1,1,1,1},};   

        std::vector<std::vector<int>> res = {{2,2,2},
                                {2,2,2},
                                {2,2,2},};
        assert(sol.largestLocal(grid) == res);
    }
    return 0;
}