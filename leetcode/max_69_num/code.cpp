#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int maximum69Number (int num) {
        std::ios_base::sync_with_stdio(0);
        
        int num_cp = num;
        int i = 0;
        int exp = -1;
        while(num_cp)
        {
            if(num_cp % 10 == 6)
            {
                exp = i;
            }
            i++;
            num_cp /= 10;
        }
        if(exp == -1)
        {
            return num;
        }
        return  num + (3 * std::pow(10, exp));
    }
};

int main()
{
    Solution sol;
    {
        int num = 9669;
        int res = 9969;
        assert(sol.maximum69Number(num) == res);
    }
    {
        int num = 9996;
        int res = 9999;
        assert(sol.maximum69Number(num) == res);
    }
    {
        int num = 9999;
        int res = 9999;
        assert(sol.maximum69Number(num) == res);
    }
    return 0;
}