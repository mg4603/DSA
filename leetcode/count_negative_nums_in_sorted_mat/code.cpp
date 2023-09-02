#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int cnt(0);
        int n = grid[0].size();
        int m = grid.size();
        for(int j(n - 1); j >= 0; j--)
        {
            for(int i(m - 1); i >= 0; i--)
            {
                if(grid[i][j] >= 0)
                {
                    break;
                }
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {{4,3,2,-1},
                                             {3,2,1,-1},
                                             {1,1,-1,-2},
                                             {-1,-1,-2,-3}};
        assert(sol.countNegatives(mat) == 8);
    }
     {
        std::vector<std::vector<int>> mat = {
            {3,2},
            {1,0},
        };
        assert(sol.countNegatives(mat) == 0);
    }
    return 0;
}