#include <iostream>
#include <assert.h>

class Solution {
public:
    int longestContinuousSubstring(std::string s) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        int len = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] != 'a' && s[i] - 1 == s[i - 1]) {
                len++;
            }else {
                res = std::max(res, len);
                len = 1;
            }
        }
        return std::max(res, len);
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abacaba";
        int res = 2;
        assert(sol.longestContinuousSubstring(s) == res);
    }
    return 0;
}