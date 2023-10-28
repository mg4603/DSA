#include <iostream>
#include <assert.h>

class Solution {
public:
    int minMaxDifference(int num) 
    {
        std::string n_str = std::to_string(num);
        
        std::string min_n = n_str;
        char first_digit = n_str[0];

        std::string max_n = n_str;
        char first_non_9_char;
        
        for(int i = 0; i < n_str.size(); i++)
        {
            if(n_str[i] != '9')
            {
                first_non_9_char = n_str[i];
                break;
            }
        }

        int res = 0;

        for(int i = 0; i < n_str.size(); i++)
        {
            if(min_n[i] == first_digit)
            {
                min_n[i] = '0';
            }
            if(max_n[i] == first_non_9_char)
            {
                max_n[i] = '9';
            }

            res *= 10;
            res += (max_n[i] - min_n[i]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        int num = 11891;
        int res = 99009;
        assert(sol.minMaxDifference(num) == res);
    }
    {
        int num = 90;
        int res = 99;
        assert(sol.minMaxDifference(num) == res);
    }
    return 0;
}