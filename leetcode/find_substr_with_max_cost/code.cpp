#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximumCostSubstring(std::string s, 
                        std::string chars, 
                        std::vector<int>& vals) {

        std::ios::sync_with_stdio(0);
        std::vector<int> mp(26);
        for(int i = 0; i < 26; i++) {
            mp[i] = i + 1;
        }

        for(int i = 0; i < chars.length(); i++) {
            mp[chars[i] - 'a'] = vals[i];
        }

        int curr = 0, res = 0;
        for(char &ch: s) {
            curr = std::max(curr + mp[ch - 'a'], 0);
            res = std::max(res, curr);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "adaa", chars = "d";
        std::vector<int> vals = {-1000};
        int res = 2;
        assert(sol.maximumCostSubstring(s, chars, vals) == res);
    }
    return 0;
}