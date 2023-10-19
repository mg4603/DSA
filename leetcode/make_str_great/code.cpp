#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string makeGood(std::string s) {
        std::string res;
        res += s[0];
        for(int i = 1; i < s.length(); i++)
        {
            if(res.length() > 0 && 
                ((std::isupper(s[i]) && 
                  res.back() == std::tolower(s[i])) ||
                 (std::isupper(res.back()) &&
                  std::tolower(res.back()) == s[i])))
            {
                res.pop_back();
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "leEeetcode";
        std::string res = "leetcode";
        assert(sol.makeGood(s) == res);
    }
    {
        std::string s = "abBAcC";
        std::string res = "";
        assert(sol.makeGood(s) == res);
    }
    {
        std::string s = "s";
        std::string res = "s";
        assert(sol.makeGood(s) == res);
    }
    return 0;
}