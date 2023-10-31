#include <iostream>
#include <assert.h>

class Solution {
public:
    int differenceOfSums(int n, int m) 
    {
        int num1 = 0;
        int num2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i % m == 0)
            {
                num2 += i;
            }
            else
            {
                num1 += i;
            }
        }
        return num1 - num2;
    }
};

int main()
{
    Solution sol;
    {
        int n = 10;
        int m = 3;
        int res = 19;
        assert(sol.differenceOfSums(n, m) == res);
    }
    {
        int n = 5;
        int m = 6;
        int res = 15;
        assert(sol.differenceOfSums(n, m) == res);
    }
    {
         int n = 5;
         int m = 1;
        int res = -15;
        assert(sol.differenceOfSums(n, m) == res);
    }
    return 0;
}