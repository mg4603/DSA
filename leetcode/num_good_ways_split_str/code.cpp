#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numSplits(std::string s) {
        std::ios::sync_with_stdio(0);
        std::vector<int> l_freq(26, 0);
        std::vector<int> r_freq(26, 0);
        int left = 0;
        int right = 0;
        for(char &c: s) {
            if(r_freq[c-'a'] == 0)right++;
            r_freq[c - 'a']++;
        }
        int res = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            int idx = s[i] - 'a';
            l_freq[idx]++;
            r_freq[idx]--;
            if(r_freq[idx] == 0)right--;
            if(l_freq[idx] == 1)left++;
            if(left == right)res++;
            if(left > right)break;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aacaba";
        int res = 2;
        assert(sol.numSplits(s) == res);
    }
    return 0;
}