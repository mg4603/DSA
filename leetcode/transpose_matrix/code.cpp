#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) 
    {
        std::vector<std::vector<int>> res_matrix = 
                        std::vector<std::vector<int>>(
                            matrix[0].size(), 
                            std::vector<int>(matrix.size(), 0));

        for(int i(0); i < matrix.size(); i++)
        {
            for(int j(0); j < matrix[i].size(); j++)
            {
                res_matrix[j][i] = matrix[i][j];
            }
        }
        return res_matrix;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = 
        {
            {1,2,3}, {4,5,6}, {7,8,9},
        };
        std::vector<std::vector<int>> res_matrix = 
        {
            {1,4,7}, {2,5,8}, {3,6,9}
        };
        assert(sol.transpose(matrix) == res_matrix);
    }
    {
        std::vector<std::vector<int>> matrix = 
        {
            {1,2,3}, {4,5,6}
        };
        std::vector<std::vector<int>> res_matrix = 
        {
            {1,4}, {2,5}, {3,6}
        };
        assert(sol.transpose(matrix) == res_matrix);
    }
            
    return 0;
}