#include <iostream>
#include <assert.h>

class Solution {
public:
    int lastRemaining(int n) 
    {
        int head = 1;
        bool left = true;
        int step = 1;

        while(n > 1)
        {
            if(left || n % 2 == 1)
            {
                head += step;
            }
            
            left ^= 1;
            step *= 2;
            n /= 2;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    {
        int n = 9;
        int res = 6;
        assert(sol.lastRemaining(n) == res);
    }
    {
        int n = 1;
        int res = 1;
        assert(sol.lastRemaining(n) == res);
    }
    return 0;
}