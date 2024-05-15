#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> findFarmland(
                        std::vector<std::vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        std::vector<std::vector<int>> res;
        for(int row1= 0; row1 < n; row1++) {
            for(int col1 = 0; col1 < m; col1++) {
                if(land[row1][col1]) {
                    int x = row1; int y = col1;
                    for(;x < n && land[x][col1]; x++) {
                        for(y = col1; y < m && land[x][y]; y++) {
                            land[x][y] = 0;
                        }
                    }
                    res.push_back({row1, col1, x - 1, y - 1});
                }     
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> land = {{1,0,0},
                                              {0,1,1},
                                              {0,1,1}};
        std::vector<std::vector<int>> res = {{0,0,0,0},
                                             {1,1,2,2}};
        assert(sol.findFarmland(land) == res);
    }
    return 0;
}