#include <iostream>
#include <assert.h>

class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int rounds = time / (n - 1);
        int res = 0;
        if(rounds % 2 == 0)
        {
            res = time % (n - 1);
            res++;
        }
        else
        {
            res = n - (time % (n - 1));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 4;
        int time = 5;
        int res = 2;
        assert(sol.passThePillow(n, time) == res);
    }
    {
        int n = 3;
        int time = 2;
        int res = 3;
        assert(sol.passThePillow(n, time) == res);
    }
    return 0;
}