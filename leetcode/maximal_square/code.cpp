#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) 
    {
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<std::vector<int>> table(n, std::vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
        {
            table[i][0] = matrix[i][0] - '0';
            if(res == 0 && table[i][0] > res)
            {
                res = 1;
            }
        }

        for(int i = 0; i < m; i++)
        {
            table[0][i] = matrix[0][i] - '0';
            if(res == 0 && table[0][i] > res)
            {
                res = 1;
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    table[i][j] = std::min(table[i - 1][j - 1], 
                                           std::min(table[i - 1][j], 
                                                    table[i][j - 1])) + 1;
                }

                if(table[i][j] > res)
                {
                    res = table[i][j];
                }
            }
        }
        
        return res * res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>>  matrix = {{'1','0','1','0','0'},
                                                  {'1','0','1','1','1'},
                                                  {'1','1','1','1','1'},
                                                  {'1','0','0','1','0'}};
        int res = 4;
        assert(sol.maximalSquare(matrix) == res);
    }
    {
        std::vector<std::vector<char>>  matrix = {{'0','1'},
                                                  {'1','0'}};
        int res = 1;
        assert(sol.maximalSquare(matrix) == res);
    }
    {
        std::vector<std::vector<char>>  matrix = {{'0'}};
        int res = 0;
        assert(sol.maximalSquare(matrix) == res);
    }
    return 0;
}