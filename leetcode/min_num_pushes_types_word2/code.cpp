#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::ios::sync_with_stdio(0);
        std::vector<int> freq(26, 0);
        for(char &c: word) {
            freq[c - 'a']++;
        }
        
        std::sort(freq.begin(), freq.end(), std::greater<int>());
        int res = 0;
        int mul = 1;
        
        for(int i = 0; i < 26; i += 8) {
            int letters = 0;
            for(int j = 0; j < 8 && i + j < 26; j++) {
                letters += freq[i + j];
            }
            res += (letters * mul);
            mul++;

        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "abcde";
        int res = 5;
        assert(sol.minimumPushes(word) == res);
    }
    return 0;
}