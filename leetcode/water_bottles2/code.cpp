#include <iostream>
#include <assert.h>

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        int emptyBottles = numBottles;
        numBottles = 1;
        while(emptyBottles >= numExchange) {
            res++;
            emptyBottles -= numExchange;
            numExchange++;
            emptyBottles++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int numBottles = 13, numExchange = 6, res = 15;
        assert(sol.maxBottlesDrunk(numBottles, numExchange) == res);
    }
    return 0;
}