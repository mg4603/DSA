#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(
                    std::vector<std::vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        int max_val = m + n;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)continue;
                int top = max_val;
                int left = max_val;
                
                if(i - 1 >= 0)top = mat[i - 1][j];
                if(j - 1 >= 0)left = mat[i][j - 1];

                mat[i][j] = std::min(top, left) + 1;
            }
        }

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(mat[i][j] == 0)continue;
                int bottom = max_val;
                int right = max_val;
                
                if(i + 1 < n)bottom = mat[i + 1][j];
                if(j + 1 < m)right = mat[i][j + 1];
                mat[i][j] = std::min(mat[i][j], 
                                std::min(bottom, right) + 1);
            }
        }
        return mat;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {{0,0,0},
                                             {0,1,0},
                                             {0,0,0}};
        std::vector<std::vector<int>> res = {{0,0,0},
                                             {0,1,0},
                                             {0,0,0}};
        assert(sol.updateMatrix(mat) == res);
    }
    return 0;
}