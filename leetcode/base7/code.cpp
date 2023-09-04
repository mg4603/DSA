#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string convertToBase7(int num) {
        if(num == 0)
        {
            return "0";
        }
        int neg(0);
        if(num < 0)
        {
            neg = 1;
            num = -num;
        }

        std::string res;

        while(num)
        {
            res = std::to_string(num % 7) + res;
            num /= 7;
        }

        if(neg)
        {
            return "-" + res;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.convertToBase7(100) == "202");
        assert(sol.convertToBase7(-7) == "-10");
    }
    return 0;
}