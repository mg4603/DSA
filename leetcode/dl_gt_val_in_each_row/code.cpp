#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int deleteGreatestValue(std::vector<std::vector<int>>& grid) 
    {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            std::sort(grid[i].begin(), grid[i].end());
        }
        for(int i = 0; i < grid[0].size(); i++)
        {
            int largest = 0;
            for(int j = 0; j < grid.size(); j++)
            {
                if(grid[j][i] > largest)
                {
                    largest = grid[j][i];
                }
            }
            res += largest;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{1,2,4},{3,3,1}};
        int res = 8;
        assert(sol.deleteGreatestValue(grid) == res);
    }
    {
        std::vector<std::vector<int>> grid = {{10}};
        int res = 10;
        assert(sol.deleteGreatestValue(grid) == res);
    }
    return 0;
}