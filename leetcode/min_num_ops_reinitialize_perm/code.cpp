#include <iostream>
#include <assert.h>

class Solution {
    
public:
    int reinitializePermutation(int n) {
        int res = 0, i = 1;
        while(res == 0 || i != 1) {
            if(i % 2) {
                i = n / 2 + (i - 1) / 2;
            } else {
                i /= 2;
            }
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 2;
        int res = 1;
        assert(sol.reinitializePermutation(n) == res);
    }
    return 0;
}