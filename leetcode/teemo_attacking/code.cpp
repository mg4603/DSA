#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        int prev(-1);
        int res(0);
        for(int time: timeSeries)
        {
            res += duration;
            if(time <= prev)
            {
                res -= std::abs(prev - time) + 1;
            }
            prev = time + duration - 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> timeSeries = {1,2};
        assert(sol.findPoisonedDuration(timeSeries, 2) == 3);
    }
    {
        std::vector<int> timeSeries = {1,4};
        assert(sol.findPoisonedDuration(timeSeries, 2) == 4);
    }
    return 0;
}