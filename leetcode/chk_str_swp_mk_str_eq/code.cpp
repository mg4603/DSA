#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        if(s1 == s2)
        {
            return true;
        }
        std::vector<int> s1_chars(26, 0);
        std::vector<int> s2_chars(26, 0);
        int uncommon = 0;
        for(int i = 0; i < s1.length(); i++)
        {
            s1_chars[s1[i] - 'a']++;
            s2_chars[s2[i] - 'a']++;
            if(s1[i] != s2[i])
            {
                uncommon++;
            }
        }
        if(uncommon != 2)
        {
            return false;
        }
        for(int i = 0; i < 26; i++)
        {
            if(s1_chars[i] != s2_chars[i])
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
        std::string s1 = "bank";
        std::string s2 = "kanb";
        bool res = true;
        assert(sol.areAlmostEqual(s1, s2) == res);
    }
    {
        std::string s1 = "attack";
        std::string s2 = "defend";
        bool res = false;
        assert(sol.areAlmostEqual(s1, s2) == res);
    }
    {
        std::string s1 = "kelb";
        std::string s2 = "kelb";
        bool res = true;
        assert(sol.areAlmostEqual(s1, s2) == res);
    }
    return 0;
}