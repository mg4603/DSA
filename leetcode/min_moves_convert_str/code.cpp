#include <iostream>
#include <assert.h>

class Solution {
public:
    int minimumMoves(std::string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'O')continue;
            if(s[i] == 'X' || 
                (i + 1 < s.length() && s[i + 1] == 'X') || 
                (i + 2 < s.length() && s[i + 2] == 'X'))
            {
                res++;
            }
            i += 2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "XXX";
        int res = 1;
        assert(sol.minimumMoves(s) == res);
    }
    {
        std::string s = "XXOX";
        int res = 2;
        assert(sol.minimumMoves(s) == res);
    }
    {
        std::string s = "OOOO";
        int res = 0;
        assert(sol.minimumMoves(s) == res);
    }
    return 0;
}