#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> luckyNumbers (std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        for(int i = 0; i < matrix.size(); i++)
        {
            auto it = std::min_element(matrix[i].begin(), matrix[i].end());
            int col = it - matrix[i].begin();
            int temp = *it;
            for(int j = 0; j < matrix.size(); j++)
            {
                if(matrix[j][col] > temp)
                {
                    temp = matrix[j][col];
                    break;
                }
            }
            if(temp == *it)
            {
                res.push_back(temp);
            }

        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>>  matrix = {
            {3,7,8},
            {9,11,13},
            {15,16,17}};
        std::vector<int> res = {15};
        assert(sol.luckyNumbers(matrix) == res);
    }
    {
        std::vector<std::vector<int>>  matrix = {
                                {1,10,4,2},{9,3,8,7},{15,16,17,12}};
        std::vector<int> res = {12};
        assert(sol.luckyNumbers(matrix) == res);
    }
    {
        std::vector<std::vector<int>>  matrix = {
                                        {7,8},{1,2}};
        std::vector<int> res = {7};
        assert(sol.luckyNumbers(matrix) == res);
    }
    return 0;
}