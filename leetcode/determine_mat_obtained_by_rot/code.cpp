#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void rotate90(std::vector<std::vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                res[j][n - i - 1] = mat[i][j];
            }
        }
        mat = res;
    }
public:
    bool findRotation(std::vector<std::vector<int>>& mat, 
                        std::vector<std::vector<int>>& target) 
    {

        if(mat == target)
        {
            return true;
        }
        for(int i = 0; i < 3; i++)
        {
            rotate90(mat);
            if(target == mat)
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
        std::vector<std::vector<int>> mat = {
            {0,1},{1,0}};
        std::vector<std::vector<int>> target = {
            {1,0},{0,1}};
        bool res = 1;
        assert(sol.findRotation(mat, target) == res);
    }
    {
        std::vector<std::vector<int>> mat = {
            {0,1},{1,1}};
        std::vector<std::vector<int>> target = {
            {1,0},{0,1}};
        bool res = 0;
        assert(sol.findRotation(mat, target) == res);
    }
    {
        std::vector<std::vector<int>> mat = {
            {0,0,0},{0,1,0},{1,1,1}};
        std::vector<std::vector<int>> target = {
            {1,1,1},{0,1,0},{0,0,0}};
        bool res = 1;
        assert(sol.findRotation(mat, target) == res);
    }
    return 0;
}