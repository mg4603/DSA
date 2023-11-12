#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numTrees(int n) 
    {
        if(n == 0)
        {
            return 0;
        }
        std::vector<int> g(n + 1, 0);

        g[0] = 1;
        g[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                g[i] += g[j - 1] * g[i - j];
            }
        }
        return g[n];
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int res = 5;
        assert(sol.numTrees(n) == res);
    }
    {
        int n = 1;
        int res = 1;
        assert(sol.numTrees(n) == res);
    }
    return 0;
}