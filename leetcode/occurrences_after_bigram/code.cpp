#include <iostream>
#include <assert.h>

#include <vector>
#include <sstream>

class Solution {
public:
    std::vector<std::string> findOcurrences(std::string text, std::string first, std::string second) {
        std::stringstream ss(text);
        std::string temp;
        
        std::vector<std::string> words;
        while(ss >> temp)
        {
            words.push_back(temp);
        }

        std::vector<std::string> res;
        for(int i = 0; i < words.size() - 2; i++)
        {
            if(words[i] == first && words[i + 1] == second)
            {
                res.push_back(words[i + 2]);
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string text = "alice is a good girl she is a good student";
        std::string first = "a";
        std::string second = "good";
        std::vector<std::string> res = {"girl","student"};
        assert(sol.findOcurrences(text, first, second) == res);
    }
    {
        std::string text = "we will we will rock you";
        std::string first = "we";
        std::string second = "will";
        std::vector<std::string> res = {"we","rock"};
        assert(sol.findOcurrences(text, first, second) == res);
    }
    return 0;
}