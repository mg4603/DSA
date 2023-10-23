#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numOfStrings(std::vector<std::string> &patterns, std::string word) 
    {
        std::ios_base::sync_with_stdio(0);
        int res = 0;
        for(int i = 0; i < patterns.size(); i++)
        {
            if(word.find(patterns[i]) != std::string::npos)
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
        std::vector<std::string> patterns = {"a","abc","bc","d"};
        std::string word = "abc";
        int res = 3;
        assert(sol.numOfStrings(patterns, word) == res);
    }
    {
        std::vector<std::string> patterns = {"a","b","c"};
        std::string word = "aaaaabbbbb";
        int res = 2;
        assert(sol.numOfStrings(patterns, word) == res);
    }
    {
        std::vector<std::string> patterns = {"a","a","a"};
        std::string word = "ab";
        int res = 3;
        assert(sol.numOfStrings(patterns, word) == res);
    }
    return 0;
}