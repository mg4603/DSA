#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numTimesAllBlue(std::vector<int>& flips) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        int maxi = 0;
        for(int i = 0; i < flips.size(); i++) {
            maxi = std::max(maxi, flips[i]);
            if(maxi == i + 1)res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> flips = {3,2,4,1,5};
        int res = 2;
        assert(sol.numTimesAllBlue(flips) == res);
    }
    return 0;
}