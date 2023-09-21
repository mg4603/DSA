#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool checkDiagonal(std::vector<std::vector<int>> &matrix, int i, int j)
    {
        int res = matrix[i][j];
        while(i < matrix.size() && j < matrix[0].size())
        {
            if(matrix[i][j] != res)
            {
                return false;
            }
            i++;j++;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
        for(int i(0); i < matrix.size(); i++)
        {
            if(!checkDiagonal(matrix, i, 0))
            {
                return false;
            }
        }
        for(int i(0); i < matrix[0].size(); i++)
        {
            if(!checkDiagonal(matrix, 0, i))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {
            {1,2,3,4},
            {5,1,2,3},
            {9,5,1,2},
        };
        assert(sol.isToeplitzMatrix(mat) == true);
    }
    {
        std::vector<std::vector<int>> mat = {
            {1,2},
            {2,2},
        };
        assert(sol.isToeplitzMatrix(mat) == false);
    }
    return 0;
}