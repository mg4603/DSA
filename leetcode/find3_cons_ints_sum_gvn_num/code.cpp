#define to_ll(x) static_cast<long long>(x)

#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<long long> sumOfThree(long long num) {
        double x = (num - 3) / 3.0;

        if(x != std::floor(x))return {};
        return {to_ll(x), to_ll(x + 1), to_ll(x + 2)};
    }
};

int main()
{
    Solution sol;
    {
        int num = 33;
        std::vector<long long> res = {10, 11, 12};
        assert(sol.sumOfThree(num) == res);
    }
    return 0;
}