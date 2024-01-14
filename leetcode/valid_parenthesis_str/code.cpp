#include <iostream>
#include <assert.h>

#include <stack>

class Solution {
public:
    bool checkValidString(std::string s) {
        std::stack<int> open;
        std::stack<int> stars;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                open.push(i);
            }
            else if(s[i] == '*')
            {
                stars.push(i);
            }
            else
            {
                if(!open.empty())
                {
                    open.pop();
                }
                else if(!stars.empty())
                {
                    stars.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(open.empty())
        {
            return true;
        }
        else
        {
            while(!open.empty() && !stars.empty())
            {
                if(open.top() < stars.top())
                {
                    open.pop();
                    stars.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return open.empty();
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "()";
        bool res = true;
        assert(sol.checkValidString(s) == res);
    }
    {
        std::string s = "(*)";
        bool res = true;
        assert(sol.checkValidString(s) == res);
    }
    {
        std::string s = "(*))";
        bool res = true;
        assert(sol.checkValidString(s) == res);
    }
    return 0;
}