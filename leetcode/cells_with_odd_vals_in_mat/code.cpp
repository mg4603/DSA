#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
        // std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));

        // for(int i = 0; i < indices.size(); i++)
        // {
        //     int r = indices[i][0];
        //     int c = indices[i][1];
        //     for(int j = 0; j < m; j++)
        //     {
        //         matrix[j][c]++;
        //     }
        //     for(int j = 0; j < n; j++)
        //     {
        //         matrix[r][j]++;
        //     }
        // }
        // int res = 0;
        // for(int i = 0; i < m; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(matrix[i][j] % 2 == 1)
        //         {
        //             res++;
        //         }
        //     }
        // }
        // return res;
        std::ios_base::sync_with_stdio(0);
        std::vector<int> rows = std::vector<int>(m, 0);
        std::vector<int> cols = std::vector<int>(n, 0);
        for(int i = 0; i < indices.size(); i++)
        {
            rows[indices[i][0]]^=1;
            cols[indices[i][1]]^=1;
        }
        int odd_rows = std::accumulate(rows.begin(), rows.end(), 0);
        int odd_cols = std::accumulate(cols.begin(), cols.end(), 0);
        int odds = odd_rows * n + odd_cols * m;
        if(odds > 0 && odd_rows > 0 && odd_cols > 0)
        {
            odds -= 2 * odd_rows * odd_cols;
        }
        return odds;
    }
};

int main()
{
    Solution sol;
    {
        int m = 2;
        int n = 3;
        std::vector<std::vector<int>> indices = {
            {0,1}, {1,1}
        };
        int res = 6;
        assert(sol.oddCells(m, n, indices) == res);
    }
    {
        int m = 2;
        int n = 2;
        std::vector<std::vector<int>> indices = {
            {1,1},{0,0}
        };
        int res = 0;
        assert(sol.oddCells(m, n, indices) == res);
    }
    return 0;
}