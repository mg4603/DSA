#include <iostream>
#include <assert.h>

#include<algorithm>

class Solution {
public:
    std::string toLowerCase(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), 
                [](unsigned char ch){return std::tolower(ch);});
        return s;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.toLowerCase("Hello") == "hello");
        assert(sol.toLowerCase("here") == "here");
        assert(sol.toLowerCase("LOVELY") == "lovely");
    }
    return 0;
}