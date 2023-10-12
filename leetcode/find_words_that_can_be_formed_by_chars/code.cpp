#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    std::vector<int> getCharFreq(std::string word)
    {
        std::vector<int> char_freq(26, 0);
        for(int i = 0; i < word.size(); i++)
        {
            char_freq[word[i] - 'a']++;
        }
        return char_freq;
    }
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::ios_base::sync_with_stdio(0);
        std::vector<int> char_freq = getCharFreq(chars);

        int res = 0;
        for(int i = 0; i < words.size(); i++)
        {
            std::vector<int> temp = getCharFreq(words[i]);

            int cnt = 0;
            for(int i = 0; i < 26; i++)
            {
                if(temp[i] <= char_freq[i])
                {
                    cnt++;
                }
            }
            if(cnt == 26)
            {
                res += words[i].size();
            }
        }
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"cat","bt","hat","tree"};
        std::string chars = "atach";
        int res = 6;
        assert(sol.countCharacters(words, chars) == res);
    }
    {
        std::vector<std::string> words = {"hello","world","leetcode"};
        std::string chars = "welldonehoneyr";
        int res = 10;
        assert(sol.countCharacters(words, chars) == res);
    }
    return 0;
}