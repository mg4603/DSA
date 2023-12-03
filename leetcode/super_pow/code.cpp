#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int mod = 1337;

    int powMod(int a, int k)
    {
        int res = 1;

        while(k)
        {
            if(k % 2 == 1)
            {
                res = (res * a) % mod;
            }
            a = ((a % mod) * (a % mod)) % mod;
            k >>= 1;
        }
        return res;
    }
public:
    int superPow(int a, std::vector<int>& b) 
    {
        if(b.empty())return 1;

        int k = b.back();
        b.pop_back();

        return powMod(superPow(a, b), 10) * powMod(a, k) % mod;
    }
};

int main()
{
    Solution sol;
    {
        int a = 2;
        std::vector<int> b = {3};
        int res = 8;
        assert(sol.superPow(a, b) == res);
    }
    {
        int a = 2;
        std::vector<int> b = {1,0};
        int res = 1024;
        assert(sol.superPow(a, b) == res);
    }
    {
        int a = 1;
        std::vector<int> b = {4,3,3,8,5,2};
        int res = 1;
        assert(sol.superPow(a, b) == res);
    }
    return 0;
}