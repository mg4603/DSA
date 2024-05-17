#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::string res;
        for(char &c: s) {
            if(c == '*') {
                res.pop_back();
            }else {
                res += c;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "leet**cod*e";
        std::string res = "lecoe";
        assert(sol.removeStars(s) == res);
    }
    return 0;
}