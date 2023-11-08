#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int row0 = 0;
        int col0 = 0;

        for(int i = 0; i < n; i++)
        {
            if(matrix[i][0] == 0)
            {
                col0 = 1;
                break;
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(matrix[0][i] == 0)
            {
                row0 = 1;
                break;
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[0][j] == 0|| matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(row0)
        {
            for(int i = 0; i < m; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(col0)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
        std::vector<std::vector<int>> res = {{1,0,1},{0,0,0},{1,0,1}};
        sol.setZeroes(matrix);   
        assert(matrix == res);
    }
    {
        std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        std::vector<std::vector<int>> res = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
        sol.setZeroes(matrix);            
        assert(matrix == res);
    }
    return 0;
}