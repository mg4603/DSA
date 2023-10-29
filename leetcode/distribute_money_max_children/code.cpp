#include <iostream>
#include <assert.h>

class Solution {
public:
    int distMoney(int money, int children) 
    {

        if(money < children)
        {
            return -1;
        }
        money -= children;
        
        int res = 0;
        while(money >= 7)
        {
            money -= 7;
            res++;
        }

        if((res > 0 && money == 3 && res == children - 1) || 
           (res == children && money > 0))
        {
            res--;
        }

        if(res > children)
        {
            res = children - 1;
        }

        return res;        
    }
};

int main()
{
    Solution sol;
    {
        int money = 20;
        int children = 3;
        int res = 1;
        assert(sol.distMoney(money, children) == res);
    }
    {
        int money = 16;
        int children = 2;
        int res = 2;
        assert(sol.distMoney(money, children) == res);
    }
    return 0;
}