#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void dfs(int curr, int n, std::vector<int> &res)
    {
        if(curr > n)
        {
            return;
        }

        res.push_back(curr);
        for(int i = 0; i < 10; i++)
        {
            int temp = 10 * curr + i;
            if(temp > n)return;
            dfs(temp, n, res);
        }
    }
public:
    std::vector<int> lexicalOrder(int n) 
    {
        std::vector<int> res;
        for(int i = 1; i < 10; i++)
        {
            dfs(i, n, res);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 13;
        std::vector<int> res = {1,10,11,12,13,2,3,4,5,6,7,8,9};
        assert(sol.lexicalOrder(n) == res);
    }
    {
        int n = 2;
        std::vector<int> res = {1,2};
        assert(sol.lexicalOrder(n) == res);
    }
    return 0;
}