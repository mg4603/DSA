#include <iostream>
#include <assert.h>

#include <vector> 
#include <unordered_map>

class Solution {
    int compare(std::unordered_map<char, int> order_pos, 
                std::string s1, std::string s2)
    {
        int i(0);
        int n(std::min(s1.length(), s2.length()));
        while(i < n)
        {
            if(order_pos[s1[i]] < order_pos[s2[i]])
            {
                return -1;
            }
            else if(order_pos[s1[i]] > order_pos[s2[i]])
            {
                return 1;
            }
            else
            {
                i++;
            }
        }
        return (s1.size() == s2.size())? 0 : (s1.size() < s2.size()) ? -1 : 1;
    }
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) 
    {
        std::unordered_map<char, int> order_pos;
        for(int i = 0; i < order.length(); i++)
        {
            order_pos[order[i]] = i;
        }
        for(int i = 1; i < words.size(); i++)
        {
            if(compare(order_pos, words[i - 1], words[i]) == 1)
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
        std::vector<std::string> words = {
            "hello","leetcode"
        };
        std::string order = "hlabcdefgijkmnopqrstuvwxyz";
        bool output = true;
        assert(sol.isAlienSorted(words, order) == output);
    }
    {
        std::vector<std::string> words = {
            "word","world","row"
        };
        std::string order = "worldabcefghijkmnpqstuvxyz";
        bool output = false;
        assert(sol.isAlienSorted(words, order) == output);
    }
    {
        std::vector<std::string> words = {
            "apple","app"
        };
        std::string order = "abcdefghijklmnopqrstuvwxyz";
        bool output = false;
        assert(sol.isAlienSorted(words, order) == output);
    }
    return 0;
}