#include <iostream>
#include <assert.h>

#include <map>
#include <vector>

class Solution {
    std::map<int, bool> memo;

public:
    bool wordBreak(std::string s, 
                   std::vector<std::string>& wordDict, 
                   int idx = 0) 
    {
        auto it = memo.find(idx);
        if(it != memo.end())
        {
            return it->second;
        }

        if(idx == s.length())
        {
            return true;
        }

        for(int i = 0; i < wordDict.size(); i++)
        {
            int pos = s.find(wordDict[i], idx);

            if(idx == pos)
            {
                if(wordBreak(s, wordDict, idx + wordDict[i].length()))
                {
                    return true;
                }
            }
        }

        memo[idx] = false;
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "leetcode";
        std::vector<std::string> wordDict = {"leet","code"};
        bool res = true;
        assert(sol.wordBreak(s, wordDict) == res);
    }
    {
        std::string s = "applepenapple";
        std::vector<std::string> wordDict = {"apple","pen"};
        bool res = true;
        assert(sol.wordBreak(s, wordDict) == res);
    }
    {
        std::string s = "catsandog";
        std::vector<std::string> wordDict = {"cats","dog","sand","and","cat"};
        bool res = false;
        assert(sol.wordBreak(s, wordDict) == res);
    }
    return 0;
}