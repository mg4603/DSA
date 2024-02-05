#include <iostream>
#include <assert.h>

class Solution {
public:
    int reachNumber(int target) {
        if(target < 0)
        {
            target = -target;
        }

        int i = 0;
        int sum = 0;
        while(true)
        {
            sum += i;
            if(sum == target)
            {
                return i;
            }

            if(sum > target && (sum - target) % 2 == 0)
            {
                return i;
            }
            i++;
        }

    }
};

int main()
{
    Solution sol;
    {
        int target = 2;
        int res = 3;
        assert(sol.reachNumber(target) == res);
    }
    {
        int target = 3;
        int res = 2;
        assert(sol.reachNumber(target) == res);
    }
    return 0;
}