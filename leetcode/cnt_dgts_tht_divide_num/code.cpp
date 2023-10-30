#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    std::vector<int> getDigits(int num)
    {
        std::vector<int> digits;
        while(num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        return digits;
    }
public:
    int countDigits(int num) 
    {
        std::vector<int> digits = getDigits(num);
        int res = 0;
        for(int i = 0; i < digits.size(); i++)
        {
            if(num % digits[i] == 0)
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
        int num = 7;
        int res = 1;
        assert(sol.countDigits(num) == res);
    }
    {
        int num = 121;
        int res = 2;
        assert(sol.countDigits(num) == res);
    }
    {
        int num = 1248;
        int res = 4;
        assert(sol.countDigits(num) == res);
    }
    return 0;
}