#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
public:
    std::string reverseWords(std::string s)
    {
        std::stringstream ss(s);
        std::string temp;
        std::string res;

        while(getline(ss, temp, ' '))
        {
            if(temp != "")
            {
                res = temp + " " + res;        
            }
        }
        if(res.back() == ' ')
        {
            res.pop_back();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "the sky is blue";
        std::string res = "blue is sky the";
        assert(sol.reverseWords(s) == res);
    }
    {
        std::string s = "  hello world  ";
        std::string res = "world hello";
        assert(sol.reverseWords(s) == res);
    }
    {
        std::string s = "a good   example";
        std::string res = "example good a";
        assert(sol.reverseWords(s) == res);
    }
    return 0;
}