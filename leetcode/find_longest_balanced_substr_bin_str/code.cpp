#include <iostream>
#include <assert.h>

class Solution {
public:
    int findTheLongestBalancedSubstring(std::string s) 
    {
        std::ios_base::sync_with_stdio(0);
        int res = 0;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0')
            {
                cnt++;
            }
            else
            {
                int one_cnt = 0;
                for(int j = i; j < i + cnt && j < s.length(); j++)
                {
                    if(s[j] != '1')
                    {
                        i = j - 1;
                        break;
                    }
                    one_cnt++;
                }
                if(res < 2 * one_cnt)
                {
                    res = 2 * one_cnt;
                }
                cnt = 0;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "01000111";
        int res = 6;
        assert(sol.findTheLongestBalancedSubstring(s) == res);
    }
    {
        std::string s = "00111";
        int res = 4;
        assert(sol.findTheLongestBalancedSubstring(s) == res);
    }
    {
        std::string s = "111";
        int res = 0;
        assert(sol.findTheLongestBalancedSubstring(s) == res);
    }
    return 0;
}