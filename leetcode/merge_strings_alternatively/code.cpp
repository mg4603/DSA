#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string res;
        int i(0);
        int j(0);
        while(i < word1.size() && j < word2.size())
        {
            res += word1[i++];
            res += word2[j++];
        }
        while(i < word1.size())
        {
            res += word1[i++];
        }
        while(j < word2.size())
        {
            res += word2[j++];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.mergeAlternately("abc", "pqr") == "apbqcr");
        assert(sol.mergeAlternately("ab", "pqrs") == "apbqrs");
        assert(sol.mergeAlternately("abcd", "pq") == "apbqcd");
    }
    return 0;
}