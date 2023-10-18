#include <iostream>
#include <assert.h>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int empty_bottles = 0;
        while(numBottles)
        {
            res += numBottles;

            empty_bottles += numBottles;

            numBottles = empty_bottles / numExchange;
            empty_bottles %= numExchange;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        int numBottles = 9;
        int numExchange = 3;
        int res = 13;
        assert(sol.numWaterBottles(numBottles, numExchange) == res);
    }
    {
        int numBottles = 15;
        int numExchange = 4;
        int res = 19;
        assert(sol.numWaterBottles(numBottles, numExchange) == res);
    }
    return 0;
}