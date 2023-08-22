#include <iostream>
#include <assert.h>

#include <sstream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::stringstream ss(s);
        std::string temp;
        int res(0);
        while(ss >> temp)
        {
            res = temp.length();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.lengthOfLastWord("Hello World") == 5);
    }
    {
        assert(sol.lengthOfLastWord("   fly me   to   the moon  ") == 4);
    }
    {
        assert(sol.lengthOfLastWord("luffy is still joyboy") == 6);
    }
    


    return 0;
}