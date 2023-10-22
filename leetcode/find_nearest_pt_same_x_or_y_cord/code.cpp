#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int nearestValidPoint(int x, int y, 
                            std::vector<std::vector<int>>& points) 
    {
        int res = -1;
        int min_dist = std::numeric_limits<int>::max();
        for(int i = 0; i < points.size(); i++)
        {
            if(points[i][0] != x && points[i][1] != y)continue;
            int temp = std::abs(points[i][0] - x) + 
                            std::abs(points[i][1] - y);
            if(temp < min_dist)
            {
                min_dist = temp;
                res = i;
            }
        }
        return res;   
    }
};

int main()
{
    Solution sol;
    {
        int x = 3;
        int y = 4;
        std::vector<std::vector<int>> points = {
            {1,2},{3,1},{2,4},{2,3},{4,4}};
        int res = 2;
        assert(sol.nearestValidPoint(x, y, points) == res);
    }
    {
        int x = 3;
        int y = 4;
        std::vector<std::vector<int>> points = {
            {3,4}};
        int res = 0;
        assert(sol.nearestValidPoint(x, y, points) == res);
    }
    {
        int x = 3;
        int y = 4;
        std::vector<std::vector<int>> points = {
            {2,3}};
        int res = -1;
        assert(sol.nearestValidPoint(x, y, points) == res);
    }
    return 0;
}