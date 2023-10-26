#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string largestGoodInteger(std::string num) 
    {
        for(int i = '9'; i >= '0'; i--)
        {
            std::string temp(3, i);
            if(num.find(temp) != std::string::npos)
            {
                return temp;
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        std::string num = "6777133339";
        std::string res = "777";
        assert(sol.largestGoodInteger(num) == res);
    }
    {
        std::string num = "2300019";
        std::string res = "000";
        assert(sol.largestGoodInteger(num) == res);
    }
    {
        std::string num = "42352338";
        std::string res = "";
        assert(sol.largestGoodInteger(num) == res);
    }
    return 0;
}