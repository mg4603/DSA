#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countPrimes(int n) 
    {
        std::vector<int> sieve(n, 0);
        int res = 0;
        for(int i = 2; i < n; i++)
        {
            if(sieve[i] == 1)continue;
            res++;
            for(int j = i * 2; j < n; j += i)
            {
                sieve[j] = 1;
            }
        }    
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 10;
        int res = 4;
        assert(sol.countPrimes(n) == res);
    }
    {
        int n = 0;
        int res = 0;
        assert(sol.countPrimes(n) == res);
    }
    {
        int n = 1;
        int res = 0;
        assert(sol.countPrimes(n) == res);
    }
    return 0;
}