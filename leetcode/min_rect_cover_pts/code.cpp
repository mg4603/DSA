#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minRectanglesToCoverPoints(
                    std::vector<std::vector<int>>& points, 
                    int w) {
        std::ios::sync_with_stdio(0);

        int n = points.size();
        std::vector<int> x(n);
        int i;

        for(i = 0; i < n; i++)x[i] = points[i][0];
        std::sort(x.begin(), x.end());
        int res = 0;
        i = 0;
        
        while(i < n) {
            i = std::upper_bound(x.begin(), 
                        x.end(), x[i] + w) - x.begin();
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> points = {{2,1},{1,0},{1,4},
                                                {1,8},{3,5},{4,6}};
        int w = 1;
        int res = 2;
        assert(sol.minRectanglesToCoverPoints(points, w) == res);
    }
    return 0;
}