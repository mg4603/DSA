#include <iostream>
#include <assert.h>

class Solution {
public:
    int findLUSlength(std::string a, std::string b) {
        if(a == b)
        {
            return -1;
        }
        return std::max(a.size(), b.size());
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.findLUSlength("aba", "cdc") == 3);
        assert(sol.findLUSlength("aaa", "bbb") == 3);
        assert(sol.findLUSlength("aaa", "aaa") == -1);
    }
    return 0;
}