#include <iostream>
#include <assert.h>

class Solution {
public:
    int minChanges(std::string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i += 2) {
            if(s[i] != s[i + 1])res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "1001";
        int res = 2;
        assert(sol.minChanges(s) == res);
    }
    return 0;
}