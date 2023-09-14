#include <iostream>
#include <assert.h>

class Solution {
public:
    int countBinarySubstrings(std::string s) {
        int current = 1, prev = 0, res = 0;
        for(int i(1); i < s.length(); i++)
        {
            if(s[i] == s[i - 1])
            {
                current++;
            }
            else
            {
                res += std::min(current, prev);
                prev = current;
                current = 1;
            }
        }
        return res + std::min(current, prev);
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.countBinarySubstrings("10101") == 4);
        assert(sol.countBinarySubstrings("00110011") == 6);
    }
    return 0;
}