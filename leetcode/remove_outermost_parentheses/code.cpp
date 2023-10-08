#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string res;
        int opened = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' && opened++ > 0)
            {
                res += s[i];
            }
            if(s[i] == ')' && opened-- > 1)
            {
                res += s[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "(()())(())";
        std::string res = "()()()";
        assert(sol.removeOuterParentheses(s) == res);
    }
    {
        std::string s = "(()())(())(()(()))";
        std::string res = "()()()()(())";
        assert(sol.removeOuterParentheses(s) == res);
    }
    {
        std::string s = "()()";
        std::string res = "";
        assert(sol.removeOuterParentheses(s) == res);
    }
    return 0;
}