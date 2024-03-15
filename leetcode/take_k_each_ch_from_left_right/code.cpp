#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int takeCharacters(std::string s, int k) {
        int n = s.length();
        std::vector<int> freq(3, 0);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 3; i++)
        {
            if(freq[i] < k)return -1;
            freq[i] = freq[i] - k;
        }

        int j = 0;
        std::vector<int> cnt(3, 0);

        for(int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
            while(cnt[s[i] - 'a'] > freq[s[i] - 'a'])
            {
                cnt[s[j] - 'a']--;
                j++;
            }
            res = std::max(res, i - j + 1);
        }

        return n - res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aabaaaacaabc";
        int k = 2;
        int res = 8;
        assert(sol.takeCharacters(s, k) == res);
    }
    return 0;
}