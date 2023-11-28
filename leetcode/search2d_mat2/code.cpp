#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool binSearch(std::vector<int> &row, int target)
    {
        int l = 0;
        int r = row.size() - 1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(row[mid] == target)
            {
                return true;
            }
            else if(row[mid] < target)
            {
                l = mid + 1;
            }
            else if(row[mid] > target)
            {
                r = mid - 1;
            }

        }
        return false;
    }
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[n-1][m-1])
        {
            return false;
        }

        for(int i = 0; i < n; i++)
        {
            if(target < matrix[i][0] || target > matrix[i][m-1])continue;
            if(binSearch(matrix[i], target))
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
        std::vector<std::vector<int>> matrix = {{1,4,7,11,15},
                                                {2,5,8,12,19},
                                                {3,6,9,16,22},
                                                {10,13,14,17,24},
                                                {18,21,23,26,30}};
        int target = 5;
        bool res = true;
        assert(sol.searchMatrix(matrix, target) == res);
    }
    {
        std::vector<std::vector<int>> matrix = {{1,4,7,11,15},
                                                {2,5,8,12,19},
                                                {3,6,9,16,22},
                                                {10,13,14,17,24},
                                                {18,21,23,26,30}};
        int target = 20;
        bool res = false;
        assert(sol.searchMatrix(matrix, target) == res);
    }
    return 0;
}