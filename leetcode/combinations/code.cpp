#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(std::vector<std::vector<int>> &res, int n, 
                std::vector<int> temp, int k, int start)
    {
        if(temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++)
        {
            temp.push_back(i);
            helper(res, n, temp, k, i + 1);
            temp.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) 
    {
        std::vector<std::vector<int>> res;
        helper(res, n, {}, k, 1);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        int k = 2;
        std::vector<std::vector<int>> res = {{1,2},{1,3},{1,4},
                                             {2,3},{2,4},{3,4}};
        assert(sol.combine(n, k) == res);
    }
    {
        int n = 1;
        int k = 1;
        std::vector<std::vector<int>> res = {{1}};
        assert(sol.combine(n, k) == res);
    }
    return 0;
}