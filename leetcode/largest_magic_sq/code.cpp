#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int largestMagicSquare(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        std::vector<std::vector<int>> rows(n + 2, 
                            std::vector<int>(m + 2));
        std::vector<std::vector<int>> cols(rows);
        std::vector<std::vector<int>> d1(rows);
        std::vector<std::vector<int>> d2(rows);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                rows[i][j] = rows[i][j-1] + grid[i - 1][j - 1];
                cols[i][j] = cols[i - 1][j] + grid[i - 1][j - 1];
                d1[i][j] = d1[i - 1][j - 1] + grid[i - 1][j - 1];
                d2[i][j] = d2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }

        int res = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = std::min(n - i, m - j); k > res; k--){
                    int sum = d1[i + k][j + k] - d1[i - 1][j - 1];
                    int match = sum == (d2[i + k][j] - 
                                d2[i - 1][j + k + 1]);

                    for(int l = 0; l <= k && match; l++){
                        match &= sum == (rows[i + l][j + k] - 
                                    rows[i + l][j - 1]);
                        match &= sum == (cols[i + k][j + l] - 
                                    cols[i - 1][j + l]);
                    }
                    if(match){
                        res = k;
                        break;
                    }
                }
            }
        }
        return res + 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{7,1,4,5,6},
                                              {2,5,1,6,4},
                                              {1,5,4,3,2},
                                              {1,2,7,3,4}};
        int res = 3;
        assert(sol.largestMagicSquare(grid) == res);
    }
    return 0;
}