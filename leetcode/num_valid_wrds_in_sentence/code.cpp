#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
    bool isValid(std::string s)
    {
        int n = s.length();
        int hyphens = 0;
        for(int i = 0; i < n; i++)
        {
            if(std::isdigit(s[i]))
            {
                return false;
            }
            if(std::isalpha(s[i]))
            {
                continue;
            }
            if(s[i] == '-')
            {   
                if(++hyphens > 1 || 
                   i == 0 || i + 1 >= n || 
                   !isalpha(s[i + 1]))return false;
            }
            // flow would only reach here if it were a punctuation
            // any punctuation has to be the last char of the word
            else if(i != n - 1)return false; 
        }
        return true;
    }
public:
    int countValidWords(std::string sentence) {
        std::stringstream ss(sentence);
        std::string token;
        int res = 0;

        while(ss >> token)
        {
            if(token == "")continue;

            if(isValid(token))
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
        std::string sentence = "cat and  dog";
        int res = 3;
        assert(sol.countValidWords(sentence) == res);
    }
    {
        std::string sentence = "!this  1-s b8d!";
        int res = 0;
        assert(sol.countValidWords(sentence) == res);
    }
    {
        std::string sentence = "alice and  bob are playing stone-game10";
        int res = 5;
        assert(sol.countValidWords(sentence) == res);
    }
    return 0;
}