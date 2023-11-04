#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) 
    {
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }    

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n / 2; j++)
            {
                std::swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = 
                                            {{1,2,3},
                                             {4,5,6},
                                             {7,8,9}};
        std::vector<std::vector<int>> res = 
                                            {{7,4,1},
                                             {8,5,2},
                                             {9,6,3}};
        sol.rotate(matrix);
        assert(matrix == res);
    }
    {
        std::vector<std::vector<int>> matrix = 
                                            {{5,1,9,11},
                                             {2,4,8,10},
                                             {13,3,6,7},
                                             {15,14,12,16}};
        std::vector<std::vector<int>> res = 
                                            {{15,13,2,5},
                                             {14,3,4,1},
                                             {12,6,8,9},
                                             {16,7,10,11}};
        sol.rotate(matrix);
        assert(matrix == res);
    }
    return 0;
}