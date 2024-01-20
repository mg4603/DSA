#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        if(n <= 3)
        {
            switch(n)
            {
                case 0:
                    return 0;
                case 1:
                    return 1;
                case 2:
                    return 2;
                case 3:
                    return 5;
            }
        }
        std::vector<int> vec(n + 1, 0);
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 5;

        for(int i = 4; i < n + 1; i++)
        {
            vec[i] = (((2 * vec[i - 1]) % mod) + (vec[i - 3] % mod)) % mod;
        }
        return vec[n];
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int res = 5;
        assert(sol.numTilings(n) == res);
    }
    return 0;
}