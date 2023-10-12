#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int distanceBetweenBusStops(std::vector<int>& distance, 
                                int start, int destination) 
    {
        if(start > destination)
        {
            int temp = start;
            start = destination;
            destination = temp;
        }
        int part1 = std::accumulate(distance.begin(), 
                                    distance.begin() + start, 0);
        int part2 = std::accumulate(distance.begin() + start, 
                                    distance.begin() + destination, 0);
        int part3 = std::accumulate(distance.begin() + destination, 
                                    distance.end(), 0);

        return std::min(part2, part1 + part3); 
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> distance = {1,2,3,4};
        int start = 0;
        int destination = 1;
        int res = 1;
        assert(sol.distanceBetweenBusStops(distance, start, destination) == res);
    }
    {
        std::vector<int> distance = {1,2,3,4};
        int start = 2;
        int destination = 3;
        int res = 3;
        assert(sol.distanceBetweenBusStops(distance, start, destination) == res);
    }
    {
        std::vector<int> distance = {1,2,3,4};
        int start = 0;
        int destination = 3;
        int res = 4;
        assert(sol.distanceBetweenBusStops(distance, start, destination) == res);
    }
    return 0;
}