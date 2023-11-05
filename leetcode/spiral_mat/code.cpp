#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        std::vector<int> res;
        int right = m - 1;
        int down = n - 1;
        int left = 0;
        int up = 0;
        while(res.size() < m * n)
        {
            for(int i = left; i <= right; i++)
            {
                res.push_back(matrix[up][i]);
            }
            if(++up > down)
            {
                break;
            }
            for(int i = up; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            if(--right < left)
            {
                break;
            }
            for(int i = right; i >= left; i--)
            {
                res.push_back(matrix[down][i]);
            }
            if(--down < up)
            {
                break;
            }
            for(int i = down; i >= up; i--)
            {
                res.push_back(matrix[i][left]);
            }
            if(++left > right)
            {
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
        std::vector<int> res = {1,2,3,6,9,8,7,4,5};
        assert(sol.spiralOrder(matrix) == res);
    }
    {
        std::vector<std::vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        std::vector<int> res = {1,2,3,4,8,12,11,10,9,5,6,7};
        assert(sol.spiralOrder(matrix) == res);
    }
    return 0;
}