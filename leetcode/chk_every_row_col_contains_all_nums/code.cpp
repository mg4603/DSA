#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool checkValid(std::vector<std::vector<int>>& matrix) 
    {
        std::ios_base::sync_with_stdio(0);
        int n = matrix.size();
        std::vector<std::unordered_set<int>> rows(n);
        std::vector<std::unordered_set<int>> cols(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                rows[i].insert(matrix[i][j]);
                cols[j].insert(matrix[i][j]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(rows[i].size() != n || cols[i].size() != n)
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
        std::vector<std::vector<int>> matrix = {{1,2,3},{3,1,2},{2,3,1}};
        bool res = 1;
        assert(sol.checkValid(matrix) == res);
    }
    {
        std::vector<std::vector<int>> matrix = {{1,1,1},{1,2,3},{1,2,3}};
        bool res = 0;
        assert(sol.checkValid(matrix) == res);
    }
    return 0;
}