#include <iostream>
#include <assert.h>

class Solution {
public:
    int countHomogenous(std::string s) 
    {
        const long long mod = 1000000007;
        int res = 0;
        char prev = s[0];
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == prev)
            {
                cnt++;
            }
            else
            {
                res += (((cnt % mod) * ((cnt + 1) % mod) / 2) % mod);
                cnt = 1;
                prev = s[i];
            }
        }

        res += (((cnt % mod) * ((cnt + 1) % mod) / 2) % mod);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abbcccaa";
        int res = 13;
        assert(sol.countHomogenous(s) == res);
    }
    {
        std::string s = "xy";
        int res = 2;
        assert(sol.countHomogenous(s) == res);
    }
    {
        std::string s = "zzzzz";
        int res = 15;
        assert(sol.countHomogenous(s) == res);
    }
    return 0;
}