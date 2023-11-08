#include <iostream>
#include <assert.h>

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) 
    {
        return (arrivalTime + delayedTime) % 24;
    }
};

int main()
{
    Solution sol;
    {
        int arrivalTime = 15;
        int delayedTime = 5 ;
        int res = 20;
        assert(sol.findDelayedArrivalTime(arrivalTime, delayedTime) == res);
    }
    {
        int arrivalTime = 13;
        int delayedTime = 11;
        int res = 0;
        assert(sol.findDelayedArrivalTime(arrivalTime, delayedTime) == res);
    }
    return 0;
}