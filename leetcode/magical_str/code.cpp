#include <iostream>
#include <assert.h>

#include <algorithm>

class Solution {
public:
    int magicalString(int n) 
    {
        if(n <= 3)
        {
            return 1;
        }
        std::string res = "122";

        int inc = 0;
        
        for(int i = 2; res.length() < n; i++)
        {
            if(res[i] == '1')
            {
                res += std::string(1, inc + '1');
            }
            else
            {
                res += std::string(2, inc + '1');
            }
            inc ^= 1;
        }
        res = res.substr(0, n);

        return std::count(res.begin(), res.end(), '1');
    }
};

int main()
{
    Solution sol;
    {
        int n = 6;
        int res = 3;
        assert(sol.magicalString(n) == res);
    }
    {
        int n = 1;
        int res = 1;
        assert(sol.magicalString(n) == res);
    }
    return 0;
}