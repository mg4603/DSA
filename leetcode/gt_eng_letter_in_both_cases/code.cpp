#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string greatestLetter(std::string s) 
    {
        std::vector<int> lower(26, 0);
        std::vector<int> upper(26, 0);
        for(int i = 0; i < s.length(); i++)
        {
            if(std::islower(s[i]))
            {
                lower[s[i] - 'a']++;
            }
            else
            {
                upper[s[i] - 'A']++;
            }
        }
        std::string res;
        for(int i = 25; i >= 0; i--)
        {
            if(lower[i] && upper[i])
            {
                res = std::string(1, 'A' + i);
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "lEeTcOdE";
        std::string res = "E";
        assert(sol.greatestLetter(s) == res);
    }
    {
        std::string s = "arRAzFif";
        std::string res = "R";
        assert(sol.greatestLetter(s) == res);
    }
    {
        std::string s = "AbCdEfGhIjK";
        std::string res = "";
        assert(sol.greatestLetter(s) == res);
    }
    return 0;
}