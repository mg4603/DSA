#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    long long getDescentPeriods(std::vector<int>& prices) {
        std::ios::sync_with_stdio(0);
        int len = 1;
        long long res = 0ll;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] + 1 == prices[i - 1]) {
                len++;
            }else {
                res += (1LL * len * (len + 1)) / 2;
                len = 1;
            }
        }
        res += (1ll * len * (len + 1)) / 2;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> prices = {3,2,1,4};
        long long res = 7;
        assert(sol.getDescentPeriods(prices) == res);
    }
    return 0;
}