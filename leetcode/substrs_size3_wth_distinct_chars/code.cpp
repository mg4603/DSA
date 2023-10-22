#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countGoodSubstrings(std::string s) {
        std::ios_base::sync_with_stdio(0);
        if(s.length() < 3)
        {
            return 0;
        }
        std::vector<int> freq(26, 0);
        int res = 0;

        freq[s[0] - 'a']++;
        freq[s[1] - 'a']++;
        freq[s[2] - 'a']++;
        if(freq[s[0] - 'a'] == 1 && 
            freq[s[1] - 'a'] == 1 && 
            freq[s[2] - 'a'] == 1)
        {
            res++;
        }

        for(int i = 3; i < s.length(); i++)
        {
            freq[s[i - 3] - 'a']--;
            int temp = ++freq[s[i] - 'a'];
            if(temp == 1 && freq[s[i - 1] - 'a'] == 1)
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "xyzzaz";
        int res = 1;
        assert(sol.countGoodSubstrings(s) == res);
    }
    {
        std::string s = "aababcabc";
        int res = 4;
        assert(sol.countGoodSubstrings(s) == res);
    }
    
    return 0;
}