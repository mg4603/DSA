#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string makeFancyString(std::string s) 
    {
        std::ios_base::sync_with_stdio(0);
        int count = 0;
        std::string res;
        char prev = s[0];
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == prev)
            {
                if(count < 2)
                {
                    res += s[i];
                }
                count++;
            }
            else
            {
                count = 1;
                res += s[i];
                prev = s[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "leeetcode";
        std::string res = "leetcode";
        assert(sol.makeFancyString(s) == res);
    }
    {
        std::string s = "aaabaaaa";
        std::string res = "aabaa";
        assert(sol.makeFancyString(s) == res);
    }
    {
        std::string s = "aab";
        std::string res = "aab";
        assert(sol.makeFancyString(s) == res);
    }
    return 0;
}