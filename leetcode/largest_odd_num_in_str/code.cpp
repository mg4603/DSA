#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string largestOddNumber(std::string num) {
        int i = num.length() - 1;
        while(i >= 0 && (num[i] - '0') % 2 == 0)
        {
            i--;
        }
        if(i == -1)
        {
            return "";
        }
        return num.substr(0, i + 1);
    }
};

int main()
{
    Solution sol;
    {
        std::string num = "52";
        std::string res = "5";
        assert(sol.largestOddNumber(num) == res);
    }
    {
        std::string num = "4206";
        std::string res = "";
        assert(sol.largestOddNumber(num) == res);
    }
    {
        std::string num = "35427";
        std::string res = "35427";
        assert(sol.largestOddNumber(num) == res);
    }
    return 0;
}