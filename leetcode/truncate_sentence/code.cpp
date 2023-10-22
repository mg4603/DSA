#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
public:
    std::string truncateSentence(std::string s, int k) 
    {
        std::string temp;
        std::stringstream ss(s);
        std::string res;
        while(ss >> temp && k)
        {
            res += temp;
            if(k-- > 1)
            {
                res += ' ';
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "Hello how are you Contestant";
        int k = 4;
        std::string res = "Hello how are you";
        assert(sol.truncateSentence(s, k) == res);
    }
    {
        std::string s = "What is the solution to this problem";
        int k = 4;
        std::string res = "What is the solution";
        assert(sol.truncateSentence(s, k) == res);
    }
    {
        std::string s = "chopper is not a tanuki";
        int k = 5;
        std::string res = "chopper is not a tanuki";
        assert(sol.truncateSentence(s, k) == res);
    }
    return 0;
}