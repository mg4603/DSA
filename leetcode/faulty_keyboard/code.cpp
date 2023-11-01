#include <iostream>
#include <assert.h>

#include <algorithm>

class Solution {
public:
    std::string finalString(std::string s) 
    {
        std::ios_base::sync_with_stdio(0);
        std::string res;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'i')
            {
                std::reverse(res.begin(), res.end());
                continue;
            }
            res += s[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "string";
        std::string res = "rtsng";
        assert(sol.finalString(s) == res);
    }
    {
        std::string s = "poiinter";
        std::string res = "ponter";
        assert(sol.finalString(s) == res);
    }
    return 0;
}