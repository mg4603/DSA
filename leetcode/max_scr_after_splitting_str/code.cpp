#include <iostream>
#include <assert.h>

#include <numeric>

class Solution {
public:
    int maxScore(std::string s) {
        int prefix_sum = (s[0] == '0'? 1: 0);
        int suffix_sum = std::accumulate(s.begin() + 1, s.end(), 0,
                                     [](int a, int b)
                                     {
                                            return  a + (b - '0');
                                     });
        int max_sum = prefix_sum + suffix_sum;

        for(int i = 1; i < s.length() - 1; i++)
        {
            if(s[i] == '0')
            {
                prefix_sum++;
            }
            else
            {
                suffix_sum --;
            }
            if(prefix_sum + suffix_sum > max_sum)
            {
                max_sum = prefix_sum + suffix_sum;
            }
        }
        return max_sum;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "011101";
        int res = 5;
        assert(sol.maxScore(s) == res);
    }
    {
        std::string s = "00111";
        int res = 5;
        assert(sol.maxScore(s) == res);
    }
    {
        std::string s = "1111";
        int res = 3;
        assert(sol.maxScore(s) == res);
    }
    return 0;
}