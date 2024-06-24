#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(std::vector<int> freq, int &res) {
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                freq[i]--;
                res++;
                helper(freq, res);
                freq[i]++;
            }
        }
    }
public:
    int numTilePossibilities(std::string tiles) {
        std::ios::sync_with_stdio(0);
        std::vector<int> freq(26, 0);
        for(char &ch: tiles) {
            freq[ch - 'A']++;
        }

        int res = 0;
        helper(freq, res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string tiles = "AAB";
        int res = 8;
        assert(sol.numTilePossibilities(tiles) == res);
    }
    return 0;
}