#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) 
    {
        while(k--)
        {
            auto it = std::max_element(gifts.begin(), gifts.end());
            *it = std::sqrt(*it);
        }
        return std::accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> gifts = {25,64,9,4,100};
        int k = 4;
        int res = 29;
        assert(sol.pickGifts(gifts, k) == res);
    }
    {
        std::vector<int> gifts = {1,1,1,1};
        int k = 4;
        int res = 4;
        assert(sol.pickGifts(gifts, k) == res);
    }
    return 0;
}