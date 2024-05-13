#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string removeOccurrences(std::string s, 
                                  std::string part) {
        int pos = s.find(part);
        while(s.length() && pos < s.length())
        {
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "daabcbaabcbc";
        std::string part = "abc";
        std::string res = "dab";
        assert(sol.removeOccurrences(s, part) == res);
    }
    return 0;
}