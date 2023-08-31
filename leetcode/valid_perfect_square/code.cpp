#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isPerfectSquare(long long num) {
        long long i(0);
        while(i * i < num)
        {
            i++;
        }
        return i * i == num;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isPerfectSquare(16) == true);
        assert(sol.isPerfectSquare(14) == false);
    }
    return 0;
}