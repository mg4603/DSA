#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    int maxFreq(std::string s, int maxLetters, 
                int minSize, int maxSize) {
        int res = 0;
        int j = 0;
        int n = s.length();

        std::unordered_map<int, int> cnt;
        std::unordered_map<std::string, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            cnt[s[i]]++;
            if(i - j + 1 > minSize)
            {
                if(--cnt[s[j]] == 0)cnt.erase(s[j]);
                j++;
            }
            if(cnt.size() <= maxLetters && i - j + 1 == minSize)
            {
                res = std::max(res, ++mp[s.substr(j, i - j + 1)]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aababcaab";
        int maxLetters = 2;
        int minSize = 3;
        int maxSize = 4;
        int res = 2;
        assert(sol.maxFreq(s, maxLetters, minSize, maxSize) == res);
    }
    return 0;
}