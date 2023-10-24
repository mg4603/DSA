#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(
                                        std::vector<int>& original, 
                                        int m, int n) 
    {
        std::ios_base::sync_with_stdio(0);
        std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
        if(m * n != original.size())
        {
            return {};
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res[i][j] = original[i * n + j];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> original = {1,2,3,4};
        int m = 2;
        int n = 2;
        std::vector<std::vector<int>> res = {{1,2},{3,4}};
        assert(sol.construct2DArray(original, m, n) == res);
    }
    {
        std::vector<int> original = {1,2,3};
        int m = 1;
        int n = 3;
        std::vector<std::vector<int>> res = {{1,2,3}};
        assert(sol.construct2DArray(original, m, n) == res);
    }
    {
        std::vector<int> original = {1,2};
        int m = 1;
        int n = 1;
        std::vector<std::vector<int>> res = {};
        assert(sol.construct2DArray(original, m, n) == res);
    }
    return 0;
}