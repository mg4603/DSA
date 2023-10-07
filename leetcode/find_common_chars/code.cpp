#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) 
    {
        std::vector<std::vector<int>> letter_freq(
                                        words.size(), std::vector<int>(26, 0));
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                letter_freq[i][words[i][j] - 'a']++;
            }
        }
        std::vector<std::string> res;
        for(int j = 0; j < 26; j++)
        {
            int count = std::numeric_limits<int>::max();
            for(int i = 0; i < words.size(); i++)
            {
                count = std::min(letter_freq[i][j], count);
            }
            for(int k = 0; k < count; k++)
            {
                res.push_back(std::string(1, j + 'a'));
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"bella","label","roller"};
        std::vector<std::string> res = {"e","l","l"};
        assert(sol.commonChars(words) == res);
    }
    {
        std::vector<std::string> words = {"cool","lock","cook"};
        std::vector<std::string> res = {"c","o"};
        assert(sol.commonChars(words) == res);
    }
    return 0;
}