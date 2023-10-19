#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int temp = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            if(temp != 1)continue;

            int pos = std::find(mat[i].begin(), 
                                mat[i].end(), 1) - mat[i].begin();
            int col_sum = 0;
            for(int j = 0; j < n; j++)
            {
                col_sum += mat[j][pos];
            }
            if(col_sum == 1)
            {
                res++;
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
            {1,0,0},{0,0,1},{1,0,0}
        };
        int res = 1;
        assert(sol.numSpecial(mat) == res);
    }
    {
        std::vector<std::vector<int>> mat = {
            {1,0,0},{0,1,0},{0,0,1}
        };
        int res = 3;
        assert(sol.numSpecial(mat) == res);
    }
    return 0;
}