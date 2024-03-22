#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        int n = s.length();
        int res = 0;
        int j = 0;
        std::vector<int> cnt(3, 0);

        for(int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
            while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
            {
                res += n - i;
                cnt[s[j] - 'a']--;
                j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abcabc";
        int res = 10;
        assert(sol.numberOfSubstrings(s) == res);
    }
    return 0;
}