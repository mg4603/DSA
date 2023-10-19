#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string thousandSeparator(int n) {
        if(n == 0)
        {
            return "0";
        }
        std::string res;
        int count = 0;
        while(n)
        {
            if(count == 3)
            {
                res = '.' + res;
                count = 0;
            }
            res = std::to_string(n % 10) + res;
            count++;
            n /= 10;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 987;
        std::string res = "987";
        assert(sol.thousandSeparator(n) == res);
    }
    {
        int n = 1234;
        std::string res = "1.234";
        assert(sol.thousandSeparator(n) == res);
    }
    return 0;
}