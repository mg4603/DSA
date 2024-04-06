#include <iostream>
#include <assert.h>

#include <array>
#include <vector>
#include <algorithm>

std::array<int, 2> operator+(const std::array<int, 2> &l, 
                             const std::array<int, 2> &r)
{
    return {l[0] + r[0], l[1] + r[1]};
}
std::array<int, 2> operator-(const std::array<int, 2> &l, 
                             const std::array<int, 2> &r)
{
    return {l[0] - r[0], l[1] - r[1]};
}

class Solution {
    
    int arrMin(const std::array<int, 2> &a)
    {
        return std::min(a[0], a[1]);
    }

    int factorX(int num, int x){
        int res = 0;
        while(num % x == 0)
        {
            num /= x;
            res++;
        }
        return res;
    }
public:
    int maxTrailingZeros(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<std::array<int, 2>>> h(n, 
                                std::vector<std::array<int, 2>>(m + 1));
        std::vector<std::vector<std::array<int, 2>>> v(n + 1, 
                                std::vector<std::array<int, 2>>(m));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                std::array<int, 2> fact25 = {factorX(grid[i][j], 2), 
                                            factorX(grid[i][j], 5)};
                h[i][j + 1] = h[i][j] + fact25;
                v[i + 1][j] = v[i][j] + fact25;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                std::array<int, 2> v1 = v[i + 1][j];
                std::array<int, 2> v2 = v[n][j] - v[i][j];
                std::array<int, 2> h1 = h[i][j];
                std::array<int, 2> h2 = h[i][m] - h[i][j + 1];
                
                res = std::max({res, arrMin(v1 + h1), 
                                arrMin(v2 + h1), arrMin(v1 + h2), 
                                arrMin(v2 + h2)});
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{23,17,15,3,20},
                                              {8,1,20,27,11},
                                              {9,4,6,2,21},
                                              {40,9,1,10,6},
                                              {22,7,4,5,3}};
        int res = 3;
        assert(sol.maxTrailingZeros(grid) == res);
    }
    return 0;
}