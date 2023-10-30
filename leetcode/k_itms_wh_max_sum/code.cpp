#include <iostream>
#include <assert.h>

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, 
                             int numNegOnes, int k) 
    {
        int res = 0;

        res += std::min(k, numOnes);
        k -= numOnes;

        if(k < 0)
        {
            return res;
        }

        k -= numZeros;

        if(k < 0)
        {
            return res;
        }

        res -= std::min(k, numNegOnes);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int numOnes = 3;
        int numZeros = 2;
        int numNegOnes = 0;
        int k = 2;
        int res = 2;
        assert(sol.kItemsWithMaximumSum(numOnes, numZeros,
                                         numNegOnes, k) == res);
    }
    {
        int numOnes = 3;
        int numZeros = 2;
        int numNegOnes = 0;
        int k = 4;
        int res = 3;
        assert(sol.kItemsWithMaximumSum(numOnes, numZeros,
                                         numNegOnes, k) == res);
    }
    return 0;
}