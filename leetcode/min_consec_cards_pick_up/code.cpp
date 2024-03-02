#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>
#include <limits>

class Solution {
public:
    int minimumCardPickup(std::vector<int>& cards) {
        std::unordered_map<int, int> mp;
        int res = std::numeric_limits<int>::max();
        int n = cards.size();

        for(int i = 0; i < n; i++)
        {
            if(mp.count(cards[i]))
            {
                res = std::min(res, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        return res == std::numeric_limits<int>::max() ? -1 : res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> cards = {3,4,2,3,4,7};
        int res = 4;
        assert(sol.minimumCardPickup(cards) == res);
    }
    return 0;
}