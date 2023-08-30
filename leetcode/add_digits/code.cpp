#include <iostream>
#include <assert.h>

class Solution {
    int nextNumber(int num)
    {
        int temp(0);
        while(num)
        {
            temp += num % 10;
            num /= 10;
        }
        return temp;
    }
public:
    int addDigits(int num) {
        while(num / 10 != 0)
        {
            num = nextNumber(num);
        }
        return num;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.addDigits(0) == 0);
        assert(sol.addDigits(38) == 2);
    }
    return 0;
}