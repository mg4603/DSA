#include <iostream>
#include <assert.h>

#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        
        std::stack<char> st;
        std::string opening = "([{";
        std::string closing = ")}]";

        for(char ch: s)
        {
            if(opening.find(ch) != std::string::npos)
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char top = st.top();
                if(ch == ']' && top != '[')
                {
                    return false;
                }
                if(ch == '}' && top != '{')
                {
                    return false;
                }
                if(ch == ')' && top != '(')
                {
                    return false;
                }
                st.pop();
            }
        }
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    {
        assert(sol.isValid("()") == true);
    }
    {
        assert(sol.isValid("()[]{}") == true);
    }
    {
        assert(sol.isValid("(]") == false);
    }
}