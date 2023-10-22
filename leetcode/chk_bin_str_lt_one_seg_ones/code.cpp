#include <iostream>
#include <assert.h>

class Solution {
public:
    bool checkOnesSegment(std::string s) {
        int first_zero = s.find('0');
        if(first_zero == std::string::npos)
        {
            return true;
        }
        int one_after_zero = s.find('1', first_zero);
        return one_after_zero == std::string::npos;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "1001";
        bool res = false;
        assert(sol.checkOnesSegment(s) == res);
    }
    {
        std::string s = "110";
        bool res = true;
        assert(sol.checkOnesSegment(s) == res);
    }
    return 0;
}