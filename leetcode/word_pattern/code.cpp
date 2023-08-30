#include <iostream>
#include <assert.h>

#include<map>
#include <vector>
#include <sstream>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::map<char, std::string> ch_str;
        std::map<std::string, char> str_ch;        

        std::vector<std::string> words;
        std::string temp;
        std::stringstream ss(s);
        while(ss >> temp)
        {
            words.push_back(temp);
        }

        if(words.size() != pattern.length())
        {
            return false;
        }

        for(int i(0); i < pattern.length(); i++)
        {
            if(ch_str.count(pattern[i]))
            {
                if(ch_str[pattern[i]] != words[i])
                {
                    return false;
                }
            }
            else
            {
                ch_str[pattern[i]] = words[i];
            }

            if(str_ch.count(words[i]))
            {
                if(str_ch[words[i]] != pattern[i])
                {
                    return false;
                }
            }
            else
            {
                str_ch[words[i]] = pattern[i];
            }

        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat dog";
        assert(sol.wordPattern(pattern, s) == true);
    }
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat fish";
        assert(sol.wordPattern(pattern, s) == false);
    }
    {
        std::string pattern = "aaaa";
        std::string s = "dog cat cat dog";
        assert(sol.wordPattern(pattern, s) == false);
    }
    return 0;
}