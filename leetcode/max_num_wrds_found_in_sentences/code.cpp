#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int mostWordsFound(std::vector<std::string>& sentences) 
    {
        int res = 0;
        for(int i = 0; i < sentences.size(); i++)
        {
            int words = 1;
            for(int j = 0; j < sentences[i].size(); j++)
            {
                if(sentences[i][j] == ' ')
                {
                    words++;
                }
            }
            if(words > res)
            {
                res = words;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> sentences = {
                                    "alice and bob love leetcode", 
                                    "i think so too", 
                                    "this is great thanks very much"};
        int res = 6;
        assert(sol.mostWordsFound(sentences) == res);
    }
    {
        std::vector<std::string> sentences = {
                                    "please wait", 
                                    "continue to fight", 
                                    "continue to win"};
        int res = 3;
        assert(sol.mostWordsFound(sentences) == res);
    }
    return 0;
}