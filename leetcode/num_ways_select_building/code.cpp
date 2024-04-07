#include <iostream>
#include <assert.h>

class Solution {
public:
    long long numberOfWays(std::string s) {
        std::ios::sync_with_stdio(0);
        int n = s.length();
        long long res = 0LL;
        long long suffix0 = 0LL;
        long long suffix1 = 0LL;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')suffix1++;
            else suffix0++;
        }

        long long prefix0 = 0LL;
        long long prefix1 = 0LL;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                // possible ways to generate "010" at i
                res += (prefix0 * suffix0);
                suffix1--;
                prefix1++;
            }
            else
            {
                // possible ways to generate "101" at i
                res += (prefix1 * suffix1);
                suffix0--;
                prefix0++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "001101";
        int res = 6;
        assert(sol.numberOfWays(s) == res);
    }
    return 0;
}