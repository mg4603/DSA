#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string decodeMessage(std::string key, std::string message) 
    {
        std::vector<int> table(26, -1);
        int cnt = 0;
        for(int i = 0; i < key.size(); i++)
        {
            if(key[i] == ' ' || table[key[i] - 'a'] != -1)continue;
            table[key[i] - 'a'] = cnt++;
        }
        for(int i = 0; i < message.size(); i++)
        {
            if(message[i] == ' ')continue;
            message[i] = table[message[i] - 'a'] + 'a';
        }
        return message;
    }
};

int main()
{
    Solution sol;
    {
        std::string key = "the quick brown fox jumps over the lazy dog";
        std::string message = "vkbs bs t suepuv";
        std::string res = "this is a secret";
        assert(sol.decodeMessage(key, message) == res);
    }
    {
        std::string key = "eljuxhpwnyrdgtqkviszcfmabo";
        std::string message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
        std::string res = "the five boxing wizards jump quickly";
        assert(sol.decodeMessage(key, message) == res);
    }
    return 0;
}