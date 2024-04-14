#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixBlockSum(
                    std::vector<std::vector<int>>& mat, int k) {

        std::ios::sync_with_stdio(0);
        int n = mat.size();
        int m = mat[0].size();

        std::vector<std::vector<int>> preSum = 
                    std::vector<std::vector<int>>(n + 1, 
                    std::vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                preSum[i][j] = mat[i - 1][j - 1];
                preSum[i][j] += preSum[i - 1][j];
                preSum[i][j] += preSum[i][j - 1];
                preSum[i][j] -= preSum[i - 1][j - 1];
            }
        }


        std::vector<std::vector<int>> res(n, 
                            std::vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int max_r = std::min(i + k, n - 1) + 1;
                int min_r = std::max(i - k, 0) + 1;
                int max_c = std::min(j + k, m - 1) + 1;
                int min_c = std::max(j - k, 0) + 1;
                res[i][j] = preSum[max_r][max_c];
                res[i][j] += preSum[min_r - 1][min_c - 1];
                res[i][j] -= preSum[max_r][min_c - 1];
                res[i][j] -= preSum[min_r - 1][max_c];
            }
        }
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {{1,2,3},
                                             {4,5,6},
                                             {7,8,9}};
        int k = 1;
        std::vector<std::vector<int>> res = {{12,21,16},
                                             {27,45,33},
                                             {24,39,28}};
        assert(sol.matrixBlockSum(mat, k) == res);
    }
    return 0;
}