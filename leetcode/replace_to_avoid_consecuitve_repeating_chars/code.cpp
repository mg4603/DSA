#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string modifyString(std::string s) {
        for(int i = 0; i < s.length(); i++)
        {
            char temp = 'a';
            if(s[i] == '?')
            {
                if(i == 0)
                {
                    while(s.length() > 1 && s[1] == temp)
                    {
                        temp++;
                    }
                    s[i] = temp;
                }
                else if(i == s.length() - 1)
                {
                    while(s[s.length() - 2] == temp)
                    {
                        temp++;
                    }
                    s[i] = temp;
                }
                else
                {
                    while(s[i + 1] == temp || s[i - 1] == temp)
                    {
                        temp++;
                    }
                    s[i] = temp;
                }
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "?zs";
        std::string res = "azs";
        assert(sol.modifyString(s) == res);
    }
    {
        std::string s = "ubv?w";
        std::string res = "ubvaw";
        assert(sol.modifyString(s) == res);
    }
    return 0;
}