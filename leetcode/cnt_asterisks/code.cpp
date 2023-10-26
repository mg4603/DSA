#include <iostream>
#include <assert.h>

class Solution {
public:
    int countAsterisks(std::string s) {
        int res = 0;
        int open = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(open == 1 && s[i] != '|')continue;
            else if(open == 1 && s[i] == '|'){
                open--;
                continue;
            }
            else if(s[i] == '|')
            {
                open++;
                continue;
            }
            else if(s[i] == '*')
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "l|*e*et|c**o|*de|";
        int res = 2;
        assert(sol.countAsterisks(s) == res);
    }
    {
        std::string s = "iamprogrammer";
        int res = 0;
        assert(sol.countAsterisks(s) == res);
    }
    {
        std::string s = "yo|uar|e**|b|e***au|tifu|l";
        int res = 5;
        assert(sol.countAsterisks(s) == res);
    }
    return 0;
}