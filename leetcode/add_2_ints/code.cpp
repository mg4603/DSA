#include <iostream>
#include <assert.h>

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main()
{
    Solution sol;
    {
        int num1 = 12;
        int num2 = 5;
        int res = 17;
        assert(sol.sum(num1, num2) == res);
    }
    {
        int num1 = -10;
        int num2 = 4;
        int res = -6;
        assert(sol.sum(num1, num2) == res);
    }
    return 0;
}