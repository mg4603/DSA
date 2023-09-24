#include <iostream>
#include <assert.h>

#include <stack>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        std::stack<char> s_st;
        std::stack<char> t_st;

        for(char ch: s)
        {
            if(ch == '#' && !s_st.empty())
            {
                s_st.pop();
            }
            else if(ch != '#')
            {
                s_st.push(ch);
            }
        }
        for(char ch: t)
        {
            if(ch == '#' && !t_st.empty())
            {
                t_st.pop();
            }
            else if(ch != '#')
            {
                t_st.push(ch);
            }
        }
        if(s_st.size() != t_st.size())
        {
            return false;
        }
        while(s_st.size())
        {
            if(s_st.top() != t_st.top())
            {
                return false;
            }
            s_st.pop();
            t_st.pop();
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "ab#c";
        std::string t = "ad#c";
        assert(sol.backspaceCompare(s, t) == true);
    }
    {
        std::string s = "ab##";
        std::string t = "c#d#";
        assert(sol.backspaceCompare(s, t) == true);
    }
    {
        std::string s = "a#c";
        std::string t = "b";
        assert(sol.backspaceCompare(s, t) == false);
    }
    return 0;
}