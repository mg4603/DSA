#include <iostream>
#include <assert.h>

#include <unordered_set>
#include <numeric>
#include <vector>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        std::ios::sync_with_stdio(0);
        std::vector<int> first(26, std::numeric_limits<int>::max());
        std::vector<int> last(26, 0);

        int res = 0;

        for(int i = 0; i < s.length(); i++)
        {
            int pos = s[i] - 'a';
            first[pos] = std::min(first[pos], i);
            last[pos] = std::max(last[pos], i);
        }

        for(int i = 0; i < 26; i++)
        {
            if(first[i] >= last[i])continue;
            int uniq_chars = (std::unordered_set<int>(s.begin() + 
                                first[i] + 1, s.begin() + last[i])).size();
            res += uniq_chars;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aabca";
        int res = 3;
        assert(sol.countPalindromicSubsequence(s) == res);
    }
    return 0;
}