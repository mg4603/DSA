#include <iostream>
#include <assert.h>

class Solution {
    bool evenDigitSum(int num)
    {
        int res = 0;
        while(num)
        {
            res += (num % 10);
            num /= 10;
        }
        return res % 2 == 0;
    }
public:
    int countEven(int num) {
        int res = 0;
        for(int i = 1; i <= num; i++)
        {
            if(evenDigitSum(i))res++;
        }        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int num = 4;
        int res = 2;
        assert(sol.countEven(num) == res);
    }
    {
        int num = 30;
        int res = 14;
        assert(sol.countEven(num) == res);
    }
    return 0;
}