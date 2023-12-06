#include <iostream>
#include <assert.h>

#include <stack>

class Solution {

    bool isNum(std::string val)
    {
        try
        {
            std::stoi(val);
            return true;
        }
        catch(...)
        {
            return false;
        }
    }

    std::string repeatString(std::string s, int rep)
    {
        std::string res;
        while(rep-- > 0)
        {
            res += s;
        }
        return res;
    }

public:
    std::string decodeString(std::string s) 
    {
        std::stack<std::string> st;

        std::string num;
        std::string token;
        int diff = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                if(token != "")
                {
                    st.push(token);
                    token = "";
                }
                num += s[i];
            }
            else if(s[i] == '[')
            {
                diff++;
                st.push(num);
                num = "";
            }
            else if(s[i] == ']')
            {
                while(st.size() > 0 && !isNum(st.top()))
                {
                    token = st.top() + token;
                    st.pop();
                }

                if(token == "")
                {   
                    token = st.top();
                    st.pop();
                }

                int rep = std::stoi(st.top());
                st.pop();

                std::string temp = repeatString(token, rep);
                st.push(temp);

                token = "";

            }
            else
            {
                token += s[i];
            }
            
        }

        std::string res;
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        res += token;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "3[a]2[bc]";
        std::string res = "aaabcbc";
        assert(sol.decodeString(s) == res);
    }
    {
        std::string s = "3[a2[c]]";
        std::string res = "accaccacc";
        assert(sol.decodeString(s) == res);
    }
    {
        std::string s = "2[abc]3[cd]ef";
        std::string res = "abcabccdcdcdef";
        assert(sol.decodeString(s) == res);
    }
    return 0;
}