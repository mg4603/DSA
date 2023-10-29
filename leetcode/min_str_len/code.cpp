#include <iostream>
#include <assert.h>

#include <algorithm>

class Solution {
public:
    int minimizedStringLength(std::string s) 
    {
        std::sort(s.begin(), s.end());
        int res = std::unique(s.begin(), s.end()) - s.begin();
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aaabc";
        int res = 3;
        assert(sol.minimizedStringLength(s) == res);
    }
    {
        std::string s = "cbbd";
        int res = 3;
        assert(sol.minimizedStringLength(s) == res);
    }
    {
        std::string s = "dddaaa";
        int res = 2;
        assert(sol.minimizedStringLength(s) == res);
    }
    return 0;
}