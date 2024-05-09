#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int wateringPlants(std::vector<int>& plants, int capacity) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        int curr = capacity;
        for(int i = 0; i < plants.size(); i++)
        {
            if(curr < plants[i]) {
                res += (2 * i) + 1;
                curr = capacity - plants[i];
            } else {
                res++;
                curr -= plants[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> points = {2,2,3,3};
        int capacity = 5;
        int res = 14;
        assert(sol.wateringPlants(points, capacity) == res);
    }
    return 0;
}