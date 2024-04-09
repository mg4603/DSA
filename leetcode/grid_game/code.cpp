#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>
#include <numeric>

class Solution {
public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        int n = grid[0].size();
        
        long long res = std::numeric_limits<long long>::max();

        long long top = std::accumulate(grid[0].begin(), 
                        grid[0].end(), 0LL);
        long long bottom = 0;

        for(int i = 0; i < n; i++)
        {
            top -= grid[0][i];
            res = std::min(res, std::max(top, bottom));
            bottom += grid[1][i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{2,5,4},{1,5,1}};
        int res = 4;
        assert(sol.gridGame(grid) == res);
    }
    return 0;
}