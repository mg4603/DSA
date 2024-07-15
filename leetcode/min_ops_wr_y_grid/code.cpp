#include <iostream>
#include <assert.h>

#include <vector>
#include <climits>

class Solution {
public:
    int minimumOperationsToWriteY(
                std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        int n = grid.size();
        int Y = 2 *(n / 2) + (n / 2 + 1);
        int notY = n * n - Y;
        std::vector<int> yFreq(3, 0);
        std::vector<int> notYFreq(3, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i < n / 2) {
                    if(i == j || i == n - j - 1) {
                        yFreq[grid[i][j]]++;
                    }else {
                        notYFreq[grid[i][j]]++;
                    }
                }else {
                    if(j == (n / 2)) {
                        yFreq[grid[i][j]]++;
                    }else {
                        notYFreq[grid[i][j]]++;
                    }
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0; i <= 2; i++) {
            for(int j = 0; j <= 2; j++) {
                if(i == j)continue;
                res = std::min(res, 
                        Y - yFreq[i] + notY - notYFreq[j]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{1,2,2},
                                              {1,1,0},
                                              {0,1,0}};
        int res = 3;
        assert(sol.minimumOperationsToWriteY(grid) == res);
    }
    return 0;
}