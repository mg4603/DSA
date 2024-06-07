#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        std::ios::sync_with_stdio(0);
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) {
                    if(i - 1 >= 0 && j - 1 >= 0 && dp[i - 1][j] &&
                        dp[i][j - 1] && dp[i - 1][j - 1]) {
                        dp[i][j] = std::min({dp[i - 1][j], 
                                            dp[i][j - 1], 
                                            dp[i - 1][j - 1]}) + 1;
                    } else {
                        dp[i][j]++;
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res += dp[i][j];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix ={{0,1,1,1},
                                               {1,1,1,1},
                                               {0,1,1,1}};
        int res = 15;
        assert(sol.countSquares(matrix) == res);
    }
    return 0;
}