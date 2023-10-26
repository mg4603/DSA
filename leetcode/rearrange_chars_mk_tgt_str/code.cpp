#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
    std::vector<int> getLetterFreq(std::string s)
    {
        std::vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
public:
    int rearrangeCharacters(std::string s, std::string target)
    {
        int res = std::numeric_limits<int>::max();
        std::vector<int> s_freq = getLetterFreq(s);
        std::vector<int> target_freq = getLetterFreq(target);
        for(int i = 0; i < 26; i++)
        {
            if(target_freq[i] == 0)continue;
            int temp = s_freq[i] / target_freq[i];
            if(temp < res)
            {
                res = temp;
            }
        }
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "ilovecodingonleetcode";
        std::string target = "code";
        int res = 2;
        assert(sol.rearrangeCharacters(s, target) == res);
    }
    {
        std::string s = "abcba";
        std::string target = "abc";
        int res = 1;
        assert(sol.rearrangeCharacters(s, target) == res);
    }
    {
        std::string s = "abbaccaddaeea";
        std::string target = "aaaaa";
        int res = 1;
        assert(sol.rearrangeCharacters(s, target) == res);
    }
    return 0;
}