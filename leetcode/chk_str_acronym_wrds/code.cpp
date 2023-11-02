#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isAcronym(std::vector<std::string>& words, std::string s) 
    {
        if(s.length() != words.size())
        {
            return false;
        }    
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != words[i][0])
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
        std::vector<std::string> words = {"alice","bob","charlie"};
        std::string s = "abc";
        bool res = true;
        assert(sol.isAcronym(words, s) == res);
    }
    {
        std::vector<std::string> words = {"an","apple"};
        std::string s = "a";
        bool res = false;
        assert(sol.isAcronym(words, s) == res);
    }
    {
        std::vector<std::string> words = {"never","gonna","give","up","on","you"};
        std::string s = "ngguoy";
        bool res = true;
        assert(sol.isAcronym(words, s) == res);
    }
    return 0;
}