#include <iostream>
#include <assert.h>

class Solution {
    std::string getRevBitStr(int num)
    {
        std::string res;
        while(num)
        {
            res += std::to_string(num%2);
            num /= 2;
        }
        return res;
    }
public:
    int minBitFlips(int start, int goal) {
        std::string start_bit_str = getRevBitStr(start);
        std::string goal_bit_str = getRevBitStr(goal);

        int start_len = start_bit_str.length();
        int goal_len = goal_bit_str.length();

        int n = start_len;
        if(start_len > goal_len)
        {
            n = start_len;
            goal_bit_str += std::string(start_len - goal_len, '0');
        }
        else if(start_len < goal_len)
        {
            n = goal_len;
            start_bit_str += std::string(goal_len - start_len, '0');
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(start_bit_str[i] != goal_bit_str[i])
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int start = 10;
        int goal = 7;
        int res = 3;
        assert(sol.minBitFlips(start, goal) == res);
    }
    {
        int start = 3;
        int goal = 4;
        int res = 3;
        assert(sol.minBitFlips(start, goal) == res);
    }
    return 0;
}