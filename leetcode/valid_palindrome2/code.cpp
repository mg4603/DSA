#include <iostream>
#include <assert.h>

class Solution {
    bool isPalindrome(std::string s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;j--;
        }
        return true;
    }
public:
    bool validPalindrome(std::string s) {
        int i(0);
        int j(s.length() - 1);
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
            }
                i++;j--;

        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.validPalindrome("aba") == true);
        assert(sol.validPalindrome("abca") == true);
        assert(sol.validPalindrome("abc") == false);
    }
    return 0;
}