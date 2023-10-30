#include <iostream>
#include <assert.h>

#include <vector>
#include <sstream>

class Solution {
public:
    bool isCircularSentence(std::string sentence) 
    {
        std::stringstream ss(sentence);
        std::string temp;

        std::vector<std::string> words;
        while(ss >> temp)
        {
            words.push_back(temp);    
        }
        
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            if(words[i].back() != words[(i + 1) % n][0])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string sentence = "leetcode exercises sound delightful";
        bool res = true;
        assert(sol.isCircularSentence(sentence) == res);
    }
    {
        std::string sentence = "eetcode";
        bool res = true;
        assert(sol.isCircularSentence(sentence) == res);
    }
    {
        std::string sentence = "Leetcode is cool";
        bool res = false;
        assert(sol.isCircularSentence(sentence) == res);
    }
    return 0;
}