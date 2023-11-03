#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(std::vector<std::string> &res, 
                std::string temp, int open, int close)
    {
        if(open == 0 && close == 0)
        {
            res.push_back(temp);
            return;
        }

        if(open > 0)
        {
            helper(res, temp + '(', open - 1, close);
        }

        if(close > open)
        {
            helper(res, temp + ')', open, close - 1);
        }

    }
public:
    std::vector<std::string> generateParenthesis(int n) 
    {
        std::vector<std::string> res;
        helper(res, "", n, n);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        std::vector<std::string> res = {"((()))","(()())","(())()","()(())","()()()"};

        assert(sol.generateParenthesis(n) == res);
    }
    {
        int n = 1;
        std::vector<std::string> res = {"()"};

        assert(sol.generateParenthesis(n) == res);
    }
    return 0;
}