#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string freqAlphabets(std::string s) {
        std::ios_base::sync_with_stdio(0);
        int i = 0;
        int pos = s.find('#');
        std::string res;
        while(i < s.length() && pos != std::string::npos)
        {   
            while(i < s.length() && i < pos - 2)
            {
                res += (s[i] - '1' + 'a');
                i++;
            }
            res += (std::stoi(s.substr(i)) + 'a' - 1);
            i += 3;
            pos = s.find('#', pos + 1);
        }

        while(i < s.length())
        {
            res += (s[i] - '1' + 'a');
            i++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "10#11#12";
        std::string res = "jkab";
        assert(sol.freqAlphabets(s) == res);
    }
    {
        std::string s = "1326#";
        std::string res = "acz";
        assert(sol.freqAlphabets(s) == res);
    }
    return 0;
}