#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, 
                                std::vector<std::string>& word2) 
    {
        std::string w1;
        std::string w2;
        for(int i = 0; i < word1.size(); i++)
        {
            w1 += word1[i];
        }
        for(int i = 0; i < word2.size(); i++)
        {
            w2 += word2[i];
        }
        return w1 == w2;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> word1 = {"ab", "c"};
        std::vector<std::string> word2 = {"a", "bc"};
        bool res = 1;
        assert(sol.arrayStringsAreEqual(word1, word2) == res);
    }
    {
        std::vector<std::string> word1 = {"a", "cb"};
        std::vector<std::string> word2 = {"ab", "c"};
        bool res = 0;
        assert(sol.arrayStringsAreEqual(word1, word2) == res);
    }
    {
        std::vector<std::string> word1  = {"abc", "d", "defg"};
        std::vector<std::string> word2 = {"abcddefg"};
        bool res = 1;
        assert(sol.arrayStringsAreEqual(word1, word2) == res);
    }
    return 0;
}