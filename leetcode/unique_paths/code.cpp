#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> mat(m, std::vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            mat[i][0] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            mat[0][i] = 1;
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
            }
        }
        return mat[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    {
        int m = 3;
        int n = 7;
        int res = 28;
        assert(sol.uniquePaths(m, n) == res);
    }
    {
        int m = 3;
        int n = 2;
        int res = 3;
        assert(sol.uniquePaths(m, n) == res);
    }
    return 0;
}