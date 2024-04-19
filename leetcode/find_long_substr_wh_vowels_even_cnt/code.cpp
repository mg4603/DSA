#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    int findTheLongestSubstring(std::string s) {
        std::ios::sync_with_stdio(0);
        int state = 0;
        std::unordered_map<int, int> mp;
        mp[0] = -1;
        std::string vowels = "aeiou";
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            state ^= 1 << (vowels.find(s[i]) + 1) >> 1;
            if(!mp.count(state))mp[state] = i;
            res = std::max(res, i - mp[state]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "eleetminicoworoep";
        int res = 13;
        assert(sol.findTheLongestSubstring(s) == res);
    }
    return 0;
}