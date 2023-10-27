#include <iostream>
#include <assert.h>

class Solution {
public:
    bool areNumbersAscending(std::string s) 
    {
        int pos = 0;
        int prev = -1;
        std::string digits = "0123456789";
        while(pos != std::string::npos)
        {
            pos = s.find_first_of(digits, pos);
            if(pos == std::string::npos)
            {
                break;
            }
            int current = std::stoi(s.substr(pos));
            if(current <= prev)
            {
                return false;
            }
            prev = current;
            pos = s.find_first_not_of(digits, pos);
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
        bool res = true;
        assert(sol.areNumbersAscending(s) == res);
    }
    {
        std::string s = "hello world 5 x 5";
        bool res = 0;
        assert(sol.areNumbersAscending(s) == res);
    }
    {
        std::string s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";
        bool res = 0;
        assert(sol.areNumbersAscending(s) == res);
    }
    return 0;
}