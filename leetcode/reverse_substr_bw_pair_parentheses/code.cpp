#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::vector<int> open;
        std::string res;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(')open.push_back(res.length());
            else if(s[i] == ')') {
                int j = open.back();
                open.pop_back();
                std::reverse(res.begin() + j, res.end());
            }else {
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
        std::string s = "(abcd)";
        std::string res = "dcba";
        assert(sol.reverseParentheses(s) == res);
    }
    return 0;
}