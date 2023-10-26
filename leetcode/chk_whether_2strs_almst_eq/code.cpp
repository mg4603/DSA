#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkAlmostEquivalent(std::string word1, std::string word2) 
    {
        std::vector<int> letters_w1(26, 0);
        std::vector<int> letters_w2(26, 0);
        for(int i = 0; i < word1.length(); i++)
        {
            letters_w1[word1[i] - 'a']++;
        }
        for(int i = 0; i < word2.length(); i++)
        {
            letters_w2[word2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(std::abs(letters_w1[i] - letters_w2[i]) > 3)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string word1 = "aaaa";
        std::string word2 = "bccb";
        bool res = false;
        assert(sol.checkAlmostEquivalent(word1, word2) == res);
    }
    {
        std::string word1 = "abcdeef";
        std::string word2 = "abaaacc";
        bool res = true;
        assert(sol.checkAlmostEquivalent(word1, word2) == res);
    }
    {
        std::string word1 = "cccddabba";
        std::string word2 = "babababab";
        bool res = true;
        assert(sol.checkAlmostEquivalent(word1, word2) == res);
    }
    return 0;
}