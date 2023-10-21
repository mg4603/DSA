#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string maximumTime(std::string time) {
        if(time[4] == '?')
        {
            time[4] = '9';
        }
        if(time[3] == '?')
        {
            time[3] = '5';
        }

        if(time[0] == '?' && time[1] == '?')
        {
            time[0] = '2';
            time[1] = '3';
        }

        if(time[0] != '?' && time[1] == '?')
        {
            if(time[0] == '0' || time[0] == '1')
            {
                time[1] = '9';
            }
            else
            {
                time[1] = '3';
            }
        }

        if(time[1] != '?' && time[0] == '?')
        {
            if(time[1] < '4')
            {
                time[0] = '2';
            }
            else
            {
                time[0] = '1';
            }
        }
        return time;
    }
};

int main()
{
    Solution sol;
    {
        std::string time = "2?:?0";
        std::string res = "23:50";
        assert(sol.maximumTime(time) == res);
    }
    {
        std::string time = "0?:3?";
        std::string res = "09:39";
        assert(sol.maximumTime(time) == res);
    }
    {
        std::string time = "1?:22";
        std::string res = "19:22";
        assert(sol.maximumTime(time) == res);
    }
    return 0;
}