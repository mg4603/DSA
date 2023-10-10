#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::string res;

        for(int i = 0; i < s.length(); i++)
        {
            if(res.length() > 0 && res.back() == s[i])
            {
                res.pop_back();
                continue;
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abbaca";
        std::string res = "ca";
        assert(sol.removeDuplicates(s) == res);
    }
    {
        std::string s = "azxxzy";
        std::string res = "ay";
        assert(sol.removeDuplicates(s) == res);
    }
    return 0;
}