#include <iostream>
#include <assert.h>

class Solution {
public:
    int removePalindromeSub(std::string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j)
        {
            if(s[i++] != s[j--])
            {
                return 2;
            }
        }
        return 1;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "ababa";
        int res = 1;
        assert(sol.removePalindromeSub(s) == res);
    }
    {
        std::string s = "abb";
        int res = 2;
        assert(sol.removePalindromeSub(s) == res);
    }
    {
        std::string s = "baabb";
        int res = 2;
        assert(sol.removePalindromeSub(s) == res);
    }
    return 0;
}