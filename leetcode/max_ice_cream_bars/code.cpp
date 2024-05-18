#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        std::ios::sync_with_stdio(0);

        int cost = 0;
        int res = 0;
        std::vector<int> mp(1e5+1);
        for(int cost: costs) {
            mp[cost]++;
        }

        for(int i = 1; i < 1e5+1; i++) {
            if(!mp[i])continue;
            res += std::min(mp[i], coins / i);
            if(mp[i] > coins / i)break;
            coins -= i * mp[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> costs = {1,3,2,4,1};
        int coins = 7;
        int res = 4;
        assert(sol.maxIceCream(costs, coins) == res);
    }
    return 0;
}