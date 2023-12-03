#include <iostream>
#include <assert.h>

class Solution {
public:
    int getSum(int a, int b) 
    {
        int res = 0;

        int carry = 0;
        for(int i = 0; i <= 31; i++)
        {
            int temp1 = (a >> i) & 1;
            int temp2 = (b >> i) & 1;

            if(temp1 && temp2)
            {
                if(carry)
                {
                    res |= (1 << i);
                }
                else
                {
                    carry = 1;
                }
            }
            else if(temp1 || temp2)
            {
                if(!carry)
                {
                    res |= (1 << i);
                }
            }
            else
            {
                if(carry)
                {
                    res |= (1 << i);
                    carry = 0;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int a = 1;
        int b = 2;
        int res = 3;
        assert(sol.getSum(a, b) == res);
    }
    {
        int a = 3;
        int b = 2;
        int res = 5;
        assert(sol.getSum(a, b) == res);
    }
    return 0;
}