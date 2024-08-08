#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool canConstruct(std::string s, int k) {
        std::ios::sync_with_stdio(0);
        if(k > s.length())return false;
        std::vector<int> freq(26, 0);
        for(char &ch: s) {
            freq[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2)k--;
        }
        return k >= 0;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "annabelle";
        int k = 2;
        bool res = true;
        assert(sol.canConstruct(s, k) == res);
    }
    return 0;
}