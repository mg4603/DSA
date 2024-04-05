#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> rangeAddQueries(int n, 
                        std::vector<std::vector<int>>& queries) {
        int q = queries.size();
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        for(int i = 0; i < q; i++)
        {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            res[r1][c1] += 1;
            if(r2 + 1 < n && c2 + 1 < n)res[r2+1][c2+1] += 1;
            if(r2 + 1 < n)res[r2+1][c1] -= 1;
            if(c2 + 1 < n)res[r1][c2 + 1] -= 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                res[i][j] += res[i][j - 1];
            }
        }

        for(int j = 0; j < n; j++)
        {
            for(int i = 1; i < n; i++)
            {
                res[i][j] += res[i - 1][j];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        std::vector<std::vector<int>> queries = 
                                    {{1,1,2,2},{0,0,1,1}};
        std::vector<std::vector<int>> res = {{1,1,0},{1,2,1},{0,1,1}};
        assert(sol.rangeAddQueries(n, queries) == res);
    }
    return 0;
}