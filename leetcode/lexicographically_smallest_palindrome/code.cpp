#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string makeSmallestPalindrome(std::string s) 
    {
        int n = s.length();
        for(int i = 0; i < n / 2; i++)
        {
            if(s[i] < s[n - i - 1])
            {
                s[n - i - 1] = s[i];
            }
            else if(s[i] > s[n - i - 1])
            {
                s[i] = s[n - i -1];
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "egcfe";
        std::string res = "efcfe";
        assert(sol.makeSmallestPalindrome(s) == res);
    }
    {
        std::string s = "abcd";
        std::string res = "abba";
        assert(sol.makeSmallestPalindrome(s) == res);
    }
    {
        std::string s = "seven";
        std::string res = "neven";
        assert(sol.makeSmallestPalindrome(s) == res);
    }
    return 0;
}