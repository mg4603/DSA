#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) 
    {
        std::ios_base::sync_with_stdio(0);
        int pos = 0;
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == ch)
            {
                pos = i;
                break;
            }
        }
        for(int i = 0; i <= pos / 2; i++)
        {
            std::swap(word[i], word[pos - i]);
        }
        return word;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "abcdefd";;
        char ch = 'd';
        std::string res = "dcbaefd";
        assert(sol.reversePrefix(word, ch) == res);
    }
    {
        std::string word = "xyxzxe";;
        char ch = 'z';
        std::string res = "zxyxxe";
        assert(sol.reversePrefix(word, ch) == res);
    }
    {
        std::string word = "abcd";;
        char ch = 'z';
        std::string res = "abcd";
        assert(sol.reversePrefix(word, ch) == res);
    }
    return 0;
}