#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(int i, int k, int n, std::vector<int> temp, 
                std::vector<std::vector<int>> &res)
    {
        if(n == 0 && k == 0)
        {
            res.push_back(temp);
            return;
        }

        if(k <= 0 || n < 0 || i > 9)
        {
            return;
        }

        for(int j = i; j <= 9; j++)
        {
            temp.push_back(j);
            helper(j + 1, k - 1, n - j, temp, res);
            temp.pop_back();
        }

    }

public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) 
    {
        std::vector<std::vector<int>> res;

        helper(1, k, n, {}, res)    ;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int k = 3;
        int n = 7;
        std::vector<std::vector<int>> res = {{1,2,4}};
        assert(sol.combinationSum3(k, n) == res);
    }
    {
        int k = 3;
        int n = 9;
        std::vector<std::vector<int>> res = {{1,2,6},{1,3,5},{2,3,4}};
        assert(sol.combinationSum3(k, n) == res);
    }
    {
        int k = 4;
        int n = 1;
        std::vector<std::vector<int>> res = {};
        assert(sol.combinationSum3(k, n) == res);
    }
    return 0;
}