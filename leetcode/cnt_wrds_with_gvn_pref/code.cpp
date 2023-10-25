#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref) 
    {
        int res = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(words[i].find(pref) == 0)res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"pay","attention","practice","attend"};
        std::string pref = "at";
        int res = 2;
        assert(sol.prefixCount(words, pref) == res);
    }
    {
        std::vector<std::string> words = {"leetcode","win","loops","success"};
        std::string pref = "code";
        int res = 0;
        assert(sol.prefixCount(words, pref) == res);
    }
    return 0;
}