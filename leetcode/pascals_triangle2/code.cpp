#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int binomial_coeff(int n, int r)
    {
        std::vector<std::vector<int>> c(n + 1, std::vector<int>(r + 1, 0));
        for(int i(0); i <= n; i++)
        {
            for(int j(0); j <= std::min(i, r); j++)
            {
                if(j == 0 || i == j)
                {
                    c[i][j] = 1;
                }
                else
                {
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                }
            }
        }
        return c[n][r];
    }
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res;
        for(int i(0); i <= rowIndex; i++)
        {
            res.push_back(binomial_coeff(rowIndex, i));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.getRow(3) == std::vector<int>({1, 3, 3, 1}));
    }
    {
        assert(sol.getRow(0) == std::vector<int>({1}));
    }
    {
        assert(sol.getRow(1) == std::vector<int>({1, 1}));
    }
    return 0;
}