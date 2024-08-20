#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> closestDivisors(int num) {
        int n = sqrt(num + 2);
        for(int i = n; i > 0; i--) {
            if((num + 1) % i == 0)  {
                return {i, (num + 1) / i};
            }else if((num + 2) % i == 0) {
                return {i, (num + 2) / i};
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution sol;
    {
        int num = 8;
        std::vector<int> res = {3, 3};
        assert(sol.closestDivisors(num) == res);
    }
    return 0;
}