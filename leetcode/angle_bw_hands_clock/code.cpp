#include <iostream>
#include <assert.h>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = 30.0*hour + 0.5 * minutes;
        double minutes_angle = 6.0 * minutes;
        double res = std::abs(minutes_angle - hour_angle);
        res = std::min(res, 360 - res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int hour = 12, minutes = 30;
        double res = 165.0;
        assert(sol.angleClock(hour, minutes) == res);
    }
    return 0;
}