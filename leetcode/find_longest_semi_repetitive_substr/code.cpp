#include <iostream>
#include <assert.h>

class Solution {
public:
    int longestSemiRepetitiveSubstring(std::string s) 
    {
        int res = 1;
        int n = s.length();

        int j = 0;
        int last = 0;
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i - 1])
            {
                if(last)j = last;
                last = i;
            }
            res = std::max(res, i - j + 1);
        }
        return res;  
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "52233";
        int res = 4;
        assert(sol.longestSemiRepetitiveSubstring(s) == res);
    }
    return 0;
}