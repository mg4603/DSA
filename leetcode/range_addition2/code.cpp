#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
        for(int i(0); i < ops.size(); i++)
        {
            n = std::min(n, ops[i][1]);
            m = std::min(m, ops[i][0]);
        }
        return n * m;
    }
};

int main()
{
    Solution sol;
    {
        int m = 3;
        int n = 3;
        int res = 4;
        std::vector<std::vector<int>> ops = {
            {2,2},
            {3,3}
        };
        assert(sol.maxCount(m, n, ops) == res);
    }
    {
        int m = 3;
        int n = 3;
        int res = 4;
        std::vector<std::vector<int>> ops = {
            {2,2}, {3,3}, {3,3}, {3,3}, 
            {2,2}, {3,3}, {3,3}, {3,3}, 
            {2,2}, {3,3}, {3,3}, {3,3}
        };
        assert(sol.maxCount(m, n, ops) == res);
    }
    {
        int m = 3;
        int n = 3;
        int res = 9;
        std::vector<std::vector<int>> ops = {};
        assert(sol.maxCount(m, n, ops) == res);
    }
    return 0;
}