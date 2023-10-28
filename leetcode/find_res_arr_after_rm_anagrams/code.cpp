#include <iostream>
#include <assert.h>

#include <vector>

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
    std::vector<std::string> removeAnagrams(std::vector<std::string>& words) 
    {
        std::vector<std::string> res;
        for(int i = 0; i < words.size(); i++)
        {
            if(res.size() == 0)
            {
                res.push_back(words[i]);
                continue;
            }
            std::vector<int> freq1 = getLetterFreq(words[i]);
            std::vector<int> freq2 = getLetterFreq(res.back());
            int cnt = 0;
            for(int i = 0; i < 26; i++)
            {
                if(freq1[i] == freq2[i])cnt++;
            }
            if(cnt == 26)continue;
            res.push_back(words[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"abba","baba","bbaa","cd","cd"};
        std::vector<std::string> res = {"abba","cd"};
        assert(sol.removeAnagrams(words) == res);
    }
    {
        std::vector<std::string> words = {"a","b","c","d","e"};
        std::vector<std::string> res = {"a","b","c","d","e"};
        assert(sol.removeAnagrams(words) == res);
    }
    return 0;
}