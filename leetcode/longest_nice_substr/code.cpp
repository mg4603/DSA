#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string longestNiceSubstring(std::string s) 
    {
        if(s.length() < 2)
        {
            return "";
        }
        std::vector<int> lower(26, 0);
        std::vector<int> upper(26, 0);
        for(int i = 0; i < s.length(); i++)
        {
            if(std::islower(s[i]))
            {
                lower[s[i] - 'a']++;
            }
            else
            {
                upper[s[i] - 'A']++;
            }
        }
        std::string left;
        std::string right;
        for(int i = 0; i < s.length(); i++)
        {
            if(lower[std::tolower(s[i]) - 'a'] && 
                upper[std::toupper(s[i]) - 'A'])continue;
            left = longestNiceSubstring(s.substr(0, i));
            right = longestNiceSubstring(s.substr(i + 1));
            return left.length() >= right.length() ? left: right;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "YazaAay";
        std::string res = "aAa";
        assert(sol.longestNiceSubstring(s) == res);
    }
    {
        std::string s = "Bb";
        std::string res = "Bb";
        assert(sol.longestNiceSubstring(s) == res);
    }
    {
        std::string s = "c";
        std::string res = "";
        assert(sol.longestNiceSubstring(s) == res);
    }
    return 0;
}