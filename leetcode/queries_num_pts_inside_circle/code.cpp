#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <array>

class Solution {
public:
    std::vector<int> countPoints(std::vector<std::vector<int>>& points, 
                                std::vector<std::vector<int>>& queries) {

        std::vector<std::array<int, 2>> pts;
        for(int i = 0; i < points.size(); i++)
        {
            pts.push_back({points[i][0], points[i][1]});
        }
        std::sort(pts.begin(), pts.end());

        int n = queries.size();
        std::vector<int> res(n);
        for(int i = 0; i < n; i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            auto it = std::lower_bound(pts.begin(), pts.end(), 
                                std::array<int, 2>({x - r, 0}));

            for(; it != pts.end() && (*it)[0] <= x + r; it++) {
                int dx = (*it)[0] - x;
                int dy = (*it)[1] - y;
                if(dx * dx + dy * dy <= r * r)
                {
                    res[i]++;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> points = {{1,3},{3,3},{5,3},{2,2}};
        std::vector<std::vector<int>> queries = {{2,3,1},{4,3,1},{1,1,2}};
        std::vector<int> res = {3, 2, 2};
        assert(sol.countPoints(points, queries) == res);
    }
    return 0;
}