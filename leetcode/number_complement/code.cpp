#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int findComplement(int num) {
        int res(0);
        int i(0);
        while(num)
        {
            res += std::pow(2, i) * ((num % 2) ^ 1);
            num /= 2;
            i++;
        }
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.findComplement(5) == 2);
        assert(sol.findComplement(1) == 0);
    }
    return 0;
}