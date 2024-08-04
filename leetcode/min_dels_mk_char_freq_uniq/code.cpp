#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int minDeletions(std::string s) {
        std::ios::sync_with_stdio(0);
        std::vector<int> freq(26, 0);
        int max_freq = 0;
        for(char &ch: s) {
            max_freq = std::max(max_freq, ++freq[ch - 'a']);
        }

        std::unordered_map<int, int> mp;
        for(int i = 0; i < 26; i++) {
            mp[freq[i]]++;
        }
        int res = 0;

        while(max_freq > 0 && max_freq > 0) {

            int temp = (mp[max_freq] > 1 ? mp[max_freq] - 1 : 0);
            mp[max_freq - 1] += temp;
            res += temp;
            mp[max_freq] = 1;
            max_freq--;
        }
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aab";
        int res = 0;
        assert(sol.minDeletions(s) == res);
    }
    return 0;
}