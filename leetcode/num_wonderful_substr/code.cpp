#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        std::ios::sync_with_stdio(0);
        std::vector<int> cnt(1024);

        long long res = 0LL;
        int mask = 0;
        cnt[mask] = 1;
        for(int i = 0; i < word.length(); i++)
        {
            int shift = word[i] - 'a';
            mask ^= 1 << shift;
            res += cnt[mask];
            for(int j = 0; j < 10; j++)
            {
                res += cnt[mask ^ 1 << j];
            }
            cnt[mask]++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "aba";
        int res = 4;
        assert(sol.wonderfulSubstrings(word) == res);
    }
    return 0;
}