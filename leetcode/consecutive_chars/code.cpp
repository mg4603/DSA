#include <iostream>
#include <assert.h>

class Solution {
public:
    int maxPower(std::string s) {
        std::ios_base::sync_with_stdio(0);
        int max_len = 0;
        char prev = s[0];
        int count = 1;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == prev)
            {
                count++;
            }
            else
            {
                if(count > max_len)
                {
                    max_len = count;
                }
                prev = s[i];
                count = 1;
            }
        }
        if(count > max_len)
        {
            max_len = count;
        }
        return max_len;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "leetcode";
        int res = 2;
        assert(sol.maxPower(s) == res);
    }
    {
        std::string s = "abbcccddddeeeeedcba";
        int res = 5;
        assert(sol.maxPower(s) == res);
    }
    return 0;
}