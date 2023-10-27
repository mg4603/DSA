#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countPrefixes(std::vector<std::string>& words, std::string s) 
    {
        int res = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(s.find(words[i]) == 0)
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
        std::vector<std::string> words = {"a","b","c","ab","bc","abc"};
        std::string s = "abc";
        int res = 3;
        assert(sol.countPrefixes(words, s) == res);
    }
    {
        std::vector<std::string> words = {"a","a"};
        std::string s = "aa";
        int res = 2;
        assert(sol.countPrefixes(words, s) == res);
    }
    return 0;
}