#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {
        int res = -1;
        std::unordered_map<char, std::pair<int, int>> mp;
        for(int i = 0; i < s.size(); i++)
        {
            if(mp.count(s[i]) == 0)
            {
                mp[s[i]] = std::make_pair(i, -1);
            }
            else 
            {
                if(mp[s[i]].second < i)
                {
                    mp[s[i]].second = i;
                }
                std::pair<int, int> temp = mp[s[i]];
                if(temp.second - temp.first - 1 > res)
                {
                    res = temp.second - temp.first - 1;
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
        std::string s = "aa";
        int res = 0;
        assert(sol.maxLengthBetweenEqualCharacters(s) == res);
    }
    {
        std::string s = "abca";
        int res = 2;
        assert(sol.maxLengthBetweenEqualCharacters(s) == res);
    }
    {
        std::string s = "cbzxy";
        int res = -1;
        assert(sol.maxLengthBetweenEqualCharacters(s) == res);
    }
    return 0;
}