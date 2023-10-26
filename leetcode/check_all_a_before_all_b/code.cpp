#include <iostream>
#include <assert.h>

class Solution {
public:
    bool checkString(std::string s) 
    {
        int start = s.find('b');
        for(int i = start; i < s.length(); i++)
        {
            if(s[i] == 'a')
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aaabbb";
        int res = 1;
        assert(sol.checkString(s) == res);
    }
    {
        std::string s = "abab";
        int res = 0;
        assert(sol.checkString(s) == res);
    }
    {
        std::string s = "bbb";
        int res = 1;
        assert(sol.checkString(s) == res);
    }
    return 0;
}