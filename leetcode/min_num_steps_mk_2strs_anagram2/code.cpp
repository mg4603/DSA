#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::ios::sync_with_stdio(0);
        std::vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++) {
            freq[t[i] - 'a']--;
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            res += std::abs(freq[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "leetcode";
        std::string t = "coats";
        int res = 7;
        assert(sol.minSteps(s, t) == res);
    }
    return 0;
}