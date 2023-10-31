#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> mp;
        
        int res = 0;
        int i = 0;

        int n = s.length();
        int flag = 0;
        
        for(int j = 0; j < n; j++)
        {
            if(mp.count(s[j]) == 0 || mp[s[j]] < i)
            {
                mp[s[j]] = j;
                if(j == n - 1)
                {
                    flag = 1;
                }
                continue;
            }
            
            int temp = (j - i);
            if(temp > res)
            {
                res = temp;
            }
            i = mp[s[j]] + 1;
            mp[s[j]] = j;
        }

        if(flag && n - i > res)
        {
            res = n - i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abcabcbb";
        int res = 3;
        assert(sol.lengthOfLongestSubstring(s) == res);
    }
    {
        std::string s = "bbbbb";
        int res = 1;
        assert(sol.lengthOfLongestSubstring(s) == res);
    }
    {
        std::string s = "pwwkew";
        int res = 3;
        assert(sol.lengthOfLongestSubstring(s) == res);
    }
    return 0;
}