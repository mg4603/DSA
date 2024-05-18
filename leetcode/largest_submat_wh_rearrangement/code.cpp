#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSubmatrix(std::vector<std::vector<int>>& mat) {
        std::ios::sync_with_stdio(0);
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j]) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            std::sort(mat[i].begin(), mat[i].end());
            for(int j = 1; j <= m; j++) {
                res = std::max(res, j * mat[i][m - j]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = {{1,0,1,0,1}};
        int res = 3;
        assert(sol.largestSubmatrix(matrix) == res);
    }
    return 0;
}