#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
    int getDigitSum(int n)
    {
        int res = 0;
        while(n)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        std::unordered_map<int, int> boxes;
        for(int i = lowLimit; i <= highLimit; i++)
        {
            int temp = ++boxes[getDigitSum(i)];
            if(temp > res)
            {
                res = temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int lowLimit = 1;
        int highLimit = 10;
        int res = 2;
        assert(sol.countBalls(lowLimit, highLimit) == res);
    }
    {
        int lowLimit = 5;
        int highLimit = 15;
        int res = 2;
        assert(sol.countBalls(lowLimit, highLimit) == res);
    }
    {
        int lowLimit = 19;
        int highLimit = 28;
        int res = 2;
        assert(sol.countBalls(lowLimit, highLimit) == res);
    }
    return 0;
}