#include <iostream>
#include <assert.h>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        std::string doubled(s + s);
        doubled = doubled.substr(1, doubled.size() - 2);
        return doubled.find(s) != std::string::npos;
    }
};

int main()
{
    Solution sol;
    {

        assert(sol.repeatedSubstringPattern("abab") == true);
        assert(sol.repeatedSubstringPattern("aba") == false);
        assert(sol.repeatedSubstringPattern("abcabcabcabc") == true);
    }
    return 0;
}