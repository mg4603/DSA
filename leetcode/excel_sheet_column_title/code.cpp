#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string res;
        while(columnNumber)
        {
            columnNumber--;
            char temp = ('A' + columnNumber % 26);
            res =  temp + res;
            columnNumber /= 26;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.convertToTitle(1) == "A");
    }
    {
        assert(sol.convertToTitle(28) == "AB");
    }
    {
        assert(sol.convertToTitle(701) == "ZY");
    }

    return 0;
}