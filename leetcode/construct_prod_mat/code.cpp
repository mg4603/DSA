#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(
                            std::vector<std::vector<int>>& grid) 
    {
        std::ios::sync_with_stdio(0);
        int mod = 12345;

        int n = grid.size();
        int m = grid[0].size();
        int pre_prod = 1;
        int post_prod = 1;

        std::vector<std::vector<int>> pre(n, std::vector<int>(m));
        std::vector<std::vector<int>> post(n, std::vector<int>(m));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                pre[i][j] = pre_prod;
                post[n - i - 1][m - j - 1] = post_prod;

                pre_prod = ((pre_prod % mod) * 
                            (grid[i][j] % mod)) % mod;
                post_prod = ((post_prod % mod) * 
                            (grid[n - i - 1][m - j - 1] % mod)) % mod;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                grid[i][j] = ((pre[i][j] % mod) * 
                              (post[i][j] % mod)) % mod;
            }
        }
        return grid;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{1,2},{3,4}};
        std::vector<std::vector<int>> res = {{24,12},{8,6}};

        assert(sol.constructProductMatrix(grid) == res);
    }
    return 0;
}