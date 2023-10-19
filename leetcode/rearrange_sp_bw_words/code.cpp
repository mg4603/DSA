#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string reorderSpaces(std::string text) {
        std::vector<std::string> vec;
        int spaces = 0;

        std::string word;
        for(int i = 0; i < text.length(); i++)
        {
            if(word != "" && text[i] == ' ')
            {
                vec.push_back(word);
                word = "";
                spaces++;
            }
            else if(text[i] == ' ')
            {
                spaces++;
            }
            else
            {
                word += text[i];
            }
        }

        if(word != "")
        {
            vec.push_back(word);
        }
        
        std::string res;
        int in_between = 0;
        int end = 0;
        if(vec.size() != 1)
        {
            in_between = spaces / (vec.size() - 1);
            end = spaces % (vec.size() - 1);
        }
        else
        {
            end = spaces;
        }
        for(int i = 0; i < vec.size(); i++)
        {
            res += vec[i];
            if(i != vec.size() - 1 && vec.size() != 1 && in_between)
            {
                res += std::string(in_between, ' ');
            }
        }
        if(end)
        {
            res += std::string(end, ' ');
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string text = "  this   is  a sentence ";
        std::string res = "this   is   a   sentence";
        assert(sol.reorderSpaces(text) == res);
    }
    {
        std::string text = " practice   makes   perfect";
       std::string res = "practice   makes   perfect ";
        assert(sol.reorderSpaces(text) == res);
    }
    return 0;
}