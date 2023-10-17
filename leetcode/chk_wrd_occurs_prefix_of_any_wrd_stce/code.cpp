#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
public:
    int isPrefixOfWord(std::string sentence, std::string searchWord) 
    {
        std::stringstream ss(sentence);
        std::string temp;
        int i = 1;
        while(ss >> temp)
        {
            if(temp.find(searchWord) == 0)
            {
                return i;
            }
            i++;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::string sentence = "i love eating burger";
        std::string searchWord = "burg";
        int res = 4;
        assert(sol.isPrefixOfWord(sentence, searchWord) == res);
    }
    {
        std::string sentence = "this problem is an easy problem";
        std::string searchWord = "pro";
        int res = 2;
        assert(sol.isPrefixOfWord(sentence, searchWord) == res);
    }
    {
        std::string sentence = "i am tired";
        std::string searchWord = "you";
        int res = -1;
        assert(sol.isPrefixOfWord(sentence, searchWord) == res);
    }
    return 0;
}