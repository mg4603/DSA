#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        std::vector<int> res(m, 0);
        
        for(int i = 0; i < m; i++)
        {
            int width = 0;
            for(int j = 0; j < n; j++)
            {
                std::string temp = std::to_string(grid[j][i]);
                if(temp.length() > width)
                {
                    width = temp.length();
                }
            }
            res[i] = width;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {
            {1},{22},{333}};
        std::vector<int> res = {3};
        assert(sol.findColumnWidth(grid) == res);
    }
    {
        std::vector<std::vector<int>> grid = {
            {-15,1,3},{15,7,12},{5,6,-2}};
        std::vector<int> res = {3,1,2};
        assert(sol.findColumnWidth(grid) == res);
    }
    return 0;
}