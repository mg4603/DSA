#include <iostream>
#include <assert.h>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        return haystack.find(needle);
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.strStr("sadbutsad", "sad") == 0);
    }
    {
        assert(sol.strStr("leetcode", "leeto") == -1);
    }

    return 0;
}