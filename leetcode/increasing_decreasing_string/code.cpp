#include <iostream>
#include <assert.h>

#include<vector>

class Solution {
public:
    std::string sortString(std::string s) {
        std::vector<int> freq(26, 0);
        std::string res;
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        while(res.length() < s.length())
        {
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] > 0)
                {
                    res += ('a' + i);
                    freq[i]--;
                }
            }
            for(int i = 25; i >= 0; i--)
            {
                if(freq[i] > 0)
                {
                    res += ('a' + i);
                    freq[i]--;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aaaabbbbcccc";
        std::string res = "abccbaabccba";
        assert(sol.sortString(s) == res);
    }
    {
        std::string s = "rat";
        std::string res = "art";
        assert(sol.sortString(s) == res);
    }
    return 0;
}