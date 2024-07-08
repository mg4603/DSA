#include <iostream>
#include <assert.h>

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n != 1) {
            if(n % 3 == 0) {
                n /= 3;
            }else if((n - 1) % 3 == 0) {
                n--;
                n /= 3;
            }else {
                break;
            }
        }
        return n == 1;
    }
};

int main()
{
    Solution sol;
    {
        int n = 12;
        bool res = true;
        assert(sol.checkPowersOfThree(n) == res);
    }
    return 0;
}