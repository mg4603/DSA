#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
        {
            return 1;
        }
        int i = 0;
        int complement = 0;
        while(n)
        {
            complement += (std::pow(2, i) * (!(n % 2)));
            n /= 2;
            i++;
        }
        return complement;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        int res = 2;
        assert(sol.bitwiseComplement(n) == res);
    }
    {
        int n = 7;
        int res = 0;
        assert(sol.bitwiseComplement(n) == res);
    }
    {
        int n = 10;
        int res = 5;
        assert(sol.bitwiseComplement(n) == res);
    }
    return 0;
}