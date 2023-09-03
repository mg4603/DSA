#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - std::round(purchaseAmount / 10.0) * 10;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.accountBalanceAfterPurchase(9) == 90);
        assert(sol.accountBalanceAfterPurchase(15) == 80);
    }
    return 0;
}