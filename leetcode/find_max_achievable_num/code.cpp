#include <iostream>
#include <assert.h>

class Solution {
public:
    int theMaximumAchievableX(int num, int t) 
    {
        return num + 2 * t;
    }
};

int main()
{
    Solution sol;
    {
        int num = 4;
        int t = 1;
        int res = 6;
        assert(sol.theMaximumAchievableX(num, t) == res);
    }
    {
        int num = 3;
        int t = 2;
        int res = 7;
        assert(sol.theMaximumAchievableX(num, t) == res);
    }
    return 0;
}