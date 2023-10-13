#include <iostream>
#include <assert.h>

#include <limits>
#include <vector>

class Solution {
    std::vector<int> getCharFreq(std::string word)
    {
        std::vector< int> freq(26, 0);
        for(int i = 0; i < word.length(); i++)
        {   
            freq[word[i] - 'a']++;
        }
        return freq;
    }
public:
    int maxNumberOfBalloons(std::string text) {
        std::ios_base::sync_with_stdio(0);
        std::vector<int> balloon = getCharFreq("balloon");

        std::vector<int> text_freq = getCharFreq(text);

        int res = std::numeric_limits<int>::max();
        for(int i = 0; i < 26; i++)
        {
            if(balloon[i])
            {
                int temp = text_freq[i] / balloon[i];
                if(temp < res)
                {
                    res = temp;
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
        std::string text = "nlaebolko";
        int res = 1;
        assert(sol.maxNumberOfBalloons(text) == res);
    }
    {
        std::string text = "loonbalxballpoon";
        int res = 2;
        assert(sol.maxNumberOfBalloons(text) == res);
    }
    {
        std::string text = "leetcode";
        int res = 0;
        assert(sol.maxNumberOfBalloons(text) == res);
    }
    return 0;
}