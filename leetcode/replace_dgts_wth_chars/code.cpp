#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string replaceDigits(std::string s) 
    {
        std::ios_base::sync_with_stdio(0);

        for(int i = 1; i < s.length(); i += 2)
        {
            s[i] = s[i-1] + (s[i] - '0');
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "a1c1e1";
        std::string res = "abcdef";
        assert(sol.replaceDigits(s) == res);
    }
    {
        std::string s = "a1b2c3d4e";
        std::string res = "abbdcfdhe";
        assert(sol.replaceDigits(s) == res);
    }
    return 0;
}