#include <iostream>
#include <assert.h>

class Solution {
public:
    int minFlipsMonoIncr(std::string s) {
        std::ios::sync_with_stdio(0);
        
        int ones = 0;
        int res = 0;
        // trivially an empty string is monotone increasing
        // if 1 is added to end it is still monotone increasing
        // if 0 is added at end:
        //      1) all previous ones have to be made zero
        //      2) make previous flips and flip the current 0

        for(char &ch: s) {
            ones += ch - '0';
            res = std::min(ones, res + (ch == '0'));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "00110";
        int res = 1;
        assert(sol.minFlipsMonoIncr(s) == res);
    }
    return 0;
}