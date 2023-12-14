#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
    bool isNext(char a, char b)
    {
        return a == 'z' ? b == 'a' : a + 1 == b;
    }

public:
    int findSubstringInWraproundString(std::string s) 
    {
        std::unordered_map<int, int> mp;
        int n = s.length();

        int max_len = 1;
        for(int i = 0; i < n; i++)
        {
            mp[s[i]] = std::max(mp[s[i]], max_len);
            
            if(i + 1 < n && isNext(s[i], s[i + 1]))
            {
                max_len++;
            }
            else
            {
                max_len = 1;
            }
        }

        int res = 0;
        for(const std::pair<int, int> it: mp)
        {
            res += it.second;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "a";
        int res = 1;
        assert(sol.findSubstringInWraproundString(s) == res);
    }
    {
        std::string s = "cac";
        int res = 2;
        assert(sol.findSubstringInWraproundString(s) == res);
    }
    {
        std::string s = "zab";
        int res = 6;
        assert(sol.findSubstringInWraproundString(s) == res);
    }
    return 0;
}