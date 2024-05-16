#include <iostream>
#include <assert.h>

#include <vector>
#include <array>

class Solution {
public:
    std::vector<std::vector<int>> onesMinusZeros(
                    std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::array<int, 2>> rows(n, {0, 0});
        std::vector<std::array<int, 2>> cols(m, {0, 0});
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    rows[i][0]++;
                    cols[j][0]++;
                }
                else {
                    rows[i][1]++;
                    cols[j][1]++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = rows[i][1] + cols[j][1] - 
                                rows[i][0] - cols[j][0];
            }
        }
        return grid;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{0,1,1},
                                             {1,0,1},
                                             {0,0,1}};
        std::vector<std::vector<int>> res = {{0,0,4},
                                             {0,0,4},
                                             {-2,-2,2}};
        assert(sol.onesMinusZeros(grid) == res);
    }
    return 0;
}