#include <iostream>
#include <assert.h>

class Solution {
public:
    int countOperations(int num1, int num2) 
    {
        int res = 0;
        while(num1 != 0 && num2 != 0)
        {
            if(num1 > num2)
            {
                num1 -= num2;
            }
            else
            {
                num2 -= num1;
            }
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int num1 = 2;
        int num2 = 3;
        int res = 3;
        assert(sol.countOperations(num1, num2) == res);
    }
    {
        int num1 = 10;
        int num2 = 10;
        int res = 1;
        assert(sol.countOperations(num1, num2) == res);
    }
    return 0;
}