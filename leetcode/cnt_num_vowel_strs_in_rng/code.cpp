#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int vowelStrings(std::vector<std::string>& words, 
                     int left, int right) 
    {
        std::string vowels = "aeiou";
        int res = 0;
        for(int i = left; i <= right; i++)
        {
            if(vowels.find(words[i][0]) != std::string::npos &&
            vowels.find(words[i].back()) != std::string::npos)
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
        std::vector<std::string> words = {"are","amy","u"};
        int left = 0;
        int right = 2;
        int res = 2;
        assert(sol.vowelStrings(words, left, right) == res);
    }
    {
        std::vector<std::string> words = {"hey","aeo","mu","ooo","artro"};
        int left = 1;
        int right = 4;
        int res = 3;
        assert(sol.vowelStrings(words, left, right) == res);
    }
    return 0;
}