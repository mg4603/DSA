#include <iostream>
#include <assert.h>

class Solution {
public:
    int maxDepth(std::string s) {
        int res = 0;
        int counter = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                counter++;
            }
            else if(s[i] == ')')
            {
                counter--;
            }
            if(counter > res)
            {
                res = counter;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "(1+(2*3)+((8)/4))+1";
        int res = 3;
        assert(sol.maxDepth(s) == res);
    }
    {
        std::string s = "(1)+((2))+(((3)))";
        int res = 3;
        assert(sol.maxDepth(s) == res);
    }
    return 0;
}