#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countConsistentStrings(std::string allowed, 
                                std::vector<std::string>& words) {
        std::vector<bool> allowed_st(26, 0);

        for(int i = 0; i < allowed.length(); i++)
        {
            allowed_st[allowed[i] - 'a'] = 1;
        }

        int res = 0;
        for(int i = 0; i < words.size(); i++)
        {
            res++;
            for(int j = 0; j < words[i].length(); j++)
            {
                if(!allowed_st[words[i][j] - 'a'])
                {
                    res--;
                    break;
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
        std::string allowed = "ab";
        std::vector<std::string> words = {"ad","bd","aaab",
                                          "baa","badab"};
        int res = 2;
        assert(sol.countConsistentStrings(allowed, words) == res);
    }
    {
        std::string allowed = "abc";
        std::vector<std::string> words = {"a","b","c","ab",
                                          "ac","bc","abc"};
        int res = 7;
        assert(sol.countConsistentStrings(allowed, words) == res);
    }
    {
        std::string allowed = "cad";
        std::vector<std::string> words = {"cc","acd","b","ba",
                                          "bac","bad","ac","d"};
        int res = 4;
        assert(sol.countConsistentStrings(allowed, words) == res);
    }
    return 0;
}