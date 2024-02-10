#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
    bool helper(std::vector<int> &piles, int speed, int h)
    {
        int t = 0;
        for(int pile: piles)
        {
            t += std::ceil(1.0 * pile / speed);
        }
        return t <= h;
    }
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(helper(piles, mid, h))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> piles = {3,6,7,11};
        int h = 8;
        int res = 4;
        assert(sol.minEatingSpeed(piles, h) == res);
    }
    return 0;
}