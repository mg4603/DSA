#include <iostream>
#include <assert.h>

class Solution {
public:
    int minAddToMakeValid(std::string s) {
        int res = 0;
        int open = 0;
        for(char &c: s) {
            if (c == '(')open++;
            else if(c == ')' && open)open--;
            else res++;
        }
        if(open > 0)res += open;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "())";
        int res = 1;
        assert(sol.minAddToMakeValid(s) == res);
    }
    return 0;
}