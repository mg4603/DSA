#include <iostream>
#include <assert.h>

class Solution {
public:
    int countTime(std::string time) 
    {
        int res = 0;
        if(time[0] == '?' && time[1] == '?')
        {
            res += 24;
        }
        else if(time[1] == '?')
        {
            if(time[0] == '2')
            {
                res += 4;
            }
            else
            {
                res += 10;
            }
        }
        else if(time[0] == '?')
        {
            if(time[1] < '4')
            {
                res += 3;
            }
            else
            {
                res += 2;
            }
        }

        if(res == 0)
        {
            res = 1;
        }
        
        if(time[3] == '?' && time[4] == '?')
        {
            res *= 60;
        }
        else if(time[3] == '?')
        {
            res *= 6;
        }
        else if(time[4] == '?')
        {
            res *= 10;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string time = "?5:00";
        int res = 2;
        assert(sol.countTime(time) == res);
    }
    {
        std::string time = "0?:0?";
        int res = 100;
        assert(sol.countTime(time) == res);
    }
    {
        std::string time = "??:??";
        int res = 1440;
        assert(sol.countTime(time) == res);
    }
    return 0;
}