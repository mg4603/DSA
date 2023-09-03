#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int altitude(0);
        int highest_altitude(0);
        for(int i(0); i < gain.size(); i++)
        {
            altitude += gain[i];
            if(altitude > highest_altitude)
            {
                highest_altitude = altitude;
            }
        }
        return highest_altitude;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-5,1,5,0,-7};
        assert(sol.largestAltitude(nums) == 1);
    }
    {
        std::vector<int> nums = {-4,-3,-2,-1,4,3,2};
        assert(sol.largestAltitude(nums) == 0);
    }
    return 0;
}