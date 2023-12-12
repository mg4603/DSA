#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) 
    {
        std::ios_base::sync_with_stdio(0);
        std::sort(points.begin(), points.end(), 
                    [](const std::vector<int> &a, 
                        const std::vector<int> &b)
        {
            return a[1] < b[1];
        });

        int n = points.size();
        int res = 1;

        int prev = points[0][1];

        for(int i = 1; i < n; i++)
        {
            if(points[i][0] <= prev)continue;
            res++;
            prev = points[i][1];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> points = {{10,16},{2,8},
                                                {1,6},{7,12}};
        int res = 2;
        assert(sol.findMinArrowShots(points) == res);
    }
    {
        std::vector<std::vector<int>> points = {{1,2},{3,4},
                                                {5,6},{7,8}};
        int res = 4;
        assert(sol.findMinArrowShots(points) == res);
    }
    {
        std::vector<std::vector<int>> points = {{1,2},{2,3},
                                                {3,4},{4,5}};
        int res = 2;
        assert(sol.findMinArrowShots(points) == res);
    }
    return 0;
}