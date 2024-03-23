#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int dfs(std::vector<int> &cost, int i, int n, int &res)
    {
        if(i >= n)return 0;
        int a = dfs(cost, 2 * i + 1, n, res);
        int b = dfs(cost, 2 * i + 2, n, res);
        res += std::abs(a - b);
        return cost[i] + std::max(a, b);
    }
public:
    int minIncrements(int n, std::vector<int>& cost) {        
        int res = 0;
        dfs(cost, 0, n, res);
        return res;
    }
};

int main()
{
    return 0;
}