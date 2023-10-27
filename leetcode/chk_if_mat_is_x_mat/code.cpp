#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkXMatrix(std::vector<std::vector<int>>& grid) 
    {
        int n = grid.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i == j  || j == (n - i - 1)) && grid[i][j] == 0)
                {
                    return false;
                }
                if(i != j && j != (n - i - 1) && grid[i][j] != 0)
                {
                    return false;
                }

            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {
            {2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2},};
        int res = 1;
        assert(sol.checkXMatrix(grid) == res);
    }
    {
        std::vector<std::vector<int>> grid = {
            {5,7,0},{0,3,1},{0,5,0},};
        int res = 0;
        assert(sol.checkXMatrix(grid) == res);
    }
    return 0;
}