#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string longestPalindrome(std::string s) 
    {
        int n = s.length();
        if(n == 1)
        {
            return s;
        }

        int max_len = 0;
        std::string res;
        
        for(int i = 0; i < n; i++)
        {
            // even length
            int low = i - 1;
            int high = i;

            while(low >= 0 && high < n && s[low] == s[high])
            {
                low--;
                high++;
            }

            high--;
            low++;
            
            if(high - low + 1 > max_len)
            {
                max_len = high - low + 1;
                res = s.substr(low, max_len);
            }

            if(high == low && max_len < 1)
            {
                max_len = 1;
                res = s.substr(low, 1);
            }

            low = i - 1;
            high = i + 1;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                low--;
                high++;
            }

            high--;
            low++;
            
            if(high - low + 1 > max_len)
            {
                max_len = high - low + 1;
                res = s.substr(low, max_len);
            }

            if(high == low && max_len < 1)
            {
                max_len = 1;
                res = s.substr(low, 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "babad";
        std::string res = "bab";
        assert(sol.longestPalindrome(s) == res);
    }
    {
        std::string s = "cbbd";
        std::string res = "bb";
        assert(sol.longestPalindrome(s) == res);
    }
    
    return 0;
}