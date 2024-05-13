#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::ios::sync_with_stdio(0);
        std::vector<int> freq(26, 0);
        int n = s.length();
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        int res = 0;
        for(int i = 0; i < 26; i++) {
            res += std::max(0, freq[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "bab";
        std::string t = "aba";
        int res = 1;
        assert(sol.minSteps(s, t) == res);
    }
    return 0;
}