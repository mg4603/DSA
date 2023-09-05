#include <iostream>
#include <assert.h>

#include <algorithm>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        int i;
        for(i = 0; i + k < s.size(); i += (2 * k))
        {
            std::reverse(s.begin() + i, s.begin() + i + k);
        }
        if(i < s.size())
        {
            std::reverse(s.begin() + i, s.end());
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.reverseStr("abcdefg", 2) == "bacdfeg");
        assert(sol.reverseStr("abcd", 2) == "bacd");
    }
    return 0;
}