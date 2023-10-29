#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat) 
    {
        std::vector<int> res(2, 0);

        for(int i = 0; i < mat.size(); i++)
        {
            int cnt = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            if(cnt > res[1])
            {
                res[1] = cnt;
                res[0] = i;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {
            {0,1},{1,0}};
        std::vector<int> res = {0,1};
        assert(sol.rowAndMaximumOnes(mat) == res);
    }
    {
        std::vector<std::vector<int>> mat = {
            {0,0,0},{0,1,1}};
        std::vector<int> res = {1,2};
        assert(sol.rowAndMaximumOnes(mat) == res);
    }
    {
        std::vector<std::vector<int>> mat = {
            {0,0},{1,1},{0,0}};
        std::vector<int> res = {1,2};
        assert(sol.rowAndMaximumOnes(mat) == res);
    }
    return 0;
}