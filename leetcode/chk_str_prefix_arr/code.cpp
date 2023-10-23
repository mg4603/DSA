#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isPrefixString(std::string s, std::vector<std::string>& words) 
    {
        std::string current_prefix;
        for(int i = 0; i < words.size(); i++)
        {
            current_prefix += words[i];
            if(s.find(current_prefix) != 0)
            {
                return false;
            }
            if(s == current_prefix)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "iloveleetcode";
        std::vector<std::string> words = {"i","love","leetcode","apples"};
        bool res = true;
        assert(sol.isPrefixString(s, words) == res);
    }
    {
        std::string s = "iloveleetcode";
        std::vector<std::string> words = {"apples","i","love","leetcode"};
        bool res = false;
        assert(sol.isPrefixString(s, words) == res);
    }
    return 0;
}