#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        if(mat.size() * mat[0].size() != r * c)
        {
            return mat;
        }
        std::vector<std::vector<int>> res(r, std::vector<int>(c, 0));
        int l(0);
        int m(0);
        for(int i(0); i < mat.size(); i++)
        {
            for(int j(0); j < mat[0].size(); j++)
            {
                res[l][m] = mat[i][j];
                m++;
                if(m == c)
                {
                    m = 0;
                    l++;
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
        std::vector<std::vector<int>> mat = {
            {1,2},
            {3,4}
        };
        std::vector<std::vector<int>> res = {
            {1,2,3,4}
        };
        int r(1);
        int c(4);
        assert(sol.matrixReshape(mat, r, c) == res);
    }
    {
        std::vector<std::vector<int>> mat = {
            {1,2},
            {3,4}
        };
        std::vector<std::vector<int>> res = {
            {1,2},
            {3,4}
        };
        int r(2);
        int c(4);
        assert(sol.matrixReshape(mat, r, c) == res);
    }
    return 0;
}