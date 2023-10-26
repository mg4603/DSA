#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string removeDigit(std::string num, char digit) 
    {
        std::string max_str;
        for(int i = 0; i < num.length(); i++)
        {
            if(num[i] != digit)continue;
            std::string temp;
            temp += num.substr(0, i);
            if(i + 1 < num.length())
            {
                temp += num.substr(i + 1);
            }
            if(temp > max_str)
            {
                max_str = temp;
            }
        }
        return max_str;
    }
};

int main()
{
    Solution sol;
    {
        std::string number = "123";
        char digit = '3';
        std::string res = "12";
        assert(sol.removeDigit(number, digit) == res);
    }
    {
        std::string number = "1231";
        char digit = '1';
        std::string res = "231";
        assert(sol.removeDigit(number, digit) == res);
    }
    {
        std::string number = "551";
        char digit = '5';
        std::string res = "51";
        assert(sol.removeDigit(number, digit) == res);
    }
    return 0;
}