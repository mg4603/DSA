#include <iostream>
#include <assert.h>

#include <vector>

class NumMatrix {
    std::vector<std::vector<int>> prefix;
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix = matrix;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j - 1 >= 0)
                {
                    prefix[i][j] += prefix[i][j - 1];
                }
                if(i - 1 >= 0)
                {
                    prefix[i][j] += prefix[i - 1][j];
                }

                if(i - 1 >= 0 && j - 1 >= 0)
                {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int res = prefix[row2][col2];
        if(row1 - 1 >= 0)
        {
            res -= prefix[row1 - 1][col2];
        }
        if(col1 - 1 >= 0)
        {
            res -= prefix[row2][col1 - 1];
        }

        if(row1 - 1 >= 0 && col1 - 1 >= 0)
        {
            res += prefix[row1 - 1][col1 - 1];
        }
        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> mat = {{3, 0, 1, 4, 2},
                                         {5, 6, 3, 2, 1},
                                         {1, 2, 0, 1, 5},
                                         {4, 1, 0, 1, 7},
                                         {1, 0, 3, 0, 5}};
    NumMatrix obj(mat);
    assert(obj.sumRegion(2, 1, 4, 3) == 8);
    assert(obj.sumRegion(1, 1, 2, 2) == 11);
    assert(obj.sumRegion(1, 2, 2, 4) == 12);
    return 0;
}