#include <iostream>
#include <assert.h>

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;

        while(mainTank > 0)
        {
            if(mainTank >= 5)
            {
                mainTank -= 5;
                res += 5;
                if(additionalTank > 0)
                {
                    mainTank++;
                    additionalTank--;
                }
            }
            else
            {
                res += mainTank;
                mainTank = 0;
            }
        }
        
        return res * 10;
    }
};

int main()
{
    Solution sol;
    {
        int mainTank = 5;
        int additionalTank = 10;
        int res = 60;
        assert(sol.distanceTraveled(mainTank, additionalTank) == res);
    }
    {
        int mainTank = 1;
        int additionalTank = 2;
        int res = 10;
        assert(sol.distanceTraveled(mainTank, additionalTank) == res);
    }
    return 0;
}