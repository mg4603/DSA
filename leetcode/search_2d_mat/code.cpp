#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, 
                      int target) 
    {
        int n = matrix.size(); 
        int m = matrix[0].size();

        int low = 0;
        int high = n - 1;
        
        int row = 0;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(target < matrix[mid][0])
            {
                high = mid - 1;
            }
            else if(target > matrix[mid][m - 1])
            {
                low = mid + 1;
            }
            else
            {
                row = mid;
                break;
            }
        }

        low = 0;
        high = m - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(target < matrix[row][mid])
            {
                high = mid - 1;
            }
            else if(target > matrix[row][mid])
            {
                low = mid + 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = {{1,3,5,7},
                                                {10,11,16,20},
                                                {23,30,34,60}};
        int target = 3;
        bool res = true;
        assert(sol.searchMatrix(matrix, target) == res);
    }
    {
        std::vector<std::vector<int>> matrix = {{1,3,5,7},
                                                {10,11,16,20},
                                                {23,30,34,60}};
        int target = 13;
        bool res = false;
        assert(sol.searchMatrix(matrix, target) == res);
    }
    return 0;
}