#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    struct DistanceComparator{
        int rCenter;
        int cCenter;
        DistanceComparator(int rCenter, int cCenter)
        {
            this->rCenter = rCenter;
            this->cCenter = cCenter;
        }
        double getDist(int r, int c)
        {
            return std::abs(r - rCenter) + std::abs(c - cCenter);
        }
        bool operator()(const std::vector<int> c1, const std::vector<int> c2)
        {
            return getDist(c1[0], c1[1]) < getDist(c2[0], c2[1]);
        }
    };
public:
    std::vector<std::vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        std::vector<std::vector<int>> res(rows * cols, std::vector<int>(2, 0));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                res[i * cols + j][0] = i;
                res[i * cols + j][1] = j;
            }
        }
        std::sort(res.begin(), res.end(), DistanceComparator(rCenter, cCenter));
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int rows = 1;
        int cols = 2;
        int rCenter = 0;
        int cCenter = 0;
        std::vector<std::vector<int>> res = {
            {0,0},{0,1}
        };
        assert(sol.allCellsDistOrder(rows, cols, rCenter, cCenter) == res);
    }
    {
        int rows = 2;
        int cols = 2;
        int rCenter = 0;
        int cCenter = 1;
        std::vector<std::vector<int>> res = {
            {0,1},{0,0},{1,1},{1,0}
        };
        assert(sol.allCellsDistOrder(rows, cols, rCenter, cCenter) == res);
    }
    {
        int rows = 2;
        int cols = 3;
        int rCenter = 1;
        int cCenter = 2;
        std::vector<std::vector<int>> res = {
            {1,2},{0,2},{1,1},{0,1},{1,0},{0,0}
        };
        assert(sol.allCellsDistOrder(rows, cols, rCenter, cCenter) == res);
    }
    return 0;
}