#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
public:
    int canBeTypedWords(std::string text, std::string brokenLetters) 
    {
        std::stringstream ss(text);
        std::string temp;
        int res = 0;
        while(ss >> temp)
        {
            if(temp.find_first_of(brokenLetters) == std::string::npos)
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
        std::string text = "hello world";
        std::string brokenLetters = "ad";
        int res = 1;
        assert(sol.canBeTypedWords(text, brokenLetters) == res);
    }
    {
        std::string text = "leet code";
        std::string brokenLetters = "lt";
        int res = 1;
        assert(sol.canBeTypedWords(text, brokenLetters) == res);
    }
    {
        std::string text = "leet code";
        std::string brokenLetters = "e";
        int res = 0;
        assert(sol.canBeTypedWords(text, brokenLetters) == res);
    }
    return 0;
}