#include <iostream>
#include <assert.h>

#include <map>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::map<char, int> ch_mp;
        for(char ch: s)
        {
            ch_mp[ch]++;
        }
        
        int len(0);

        int odd(0);
        for(auto pair: ch_mp)
        {
            if(pair.second >= 2)
            {
                len += (pair.second / 2) * 2;
                pair.second %= 2;
            }
            if(pair.second == 1)
            {
                odd = 1;
            }
        }
        return len + odd;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.longestPalindrome("abccccdd") == 7);
        assert(sol.longestPalindrome("a") == 1);
    }
    return 0;
}