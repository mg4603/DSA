#include <iostream>
#include <assert.h>

class Solution {
public:
    int minimumSum(int n, int k) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        
        for(int i = 1; i <= k / 2 && n > 0; i++, n--) {
            res += i;
        }
        while(n-- > 0) res += k++;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5, k = 4;
        int res = 18;
        assert(sol.minimumSum(n, k) == res);
    }
    return 0;
}