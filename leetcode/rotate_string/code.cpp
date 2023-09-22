#include <iostream>
#include <assert.h>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        if(s.size() != goal.size())
        {
            return false;
        }
        goal += goal;
        return goal.find(s) != std::string::npos;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abcde";
        std::string goal = "cdeab";
        assert(sol.rotateString(s, goal));
    }
    {
        std::string s = "abcde";
        std::string goal = "abced";
        assert(!sol.rotateString(s, goal));
    }return 0;
}