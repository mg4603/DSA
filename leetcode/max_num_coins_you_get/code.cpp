#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCoins(std::vector<int>& piles) {
        std::ios::sync_with_stdio(0);
        std::sort(piles.begin(), piles.end());
        int res = 0;
        
        int sz = 0;
        int n = piles.size();

        for(int i = n - 2; i >= 0 && sz < n / 3; i-=2)
        {
            res += piles[i];
            sz += 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> piles = {2,4,1,2,7,8};
        int res = 9;
        assert(sol.maxCoins(piles) == res);
    }
    return 0;
}