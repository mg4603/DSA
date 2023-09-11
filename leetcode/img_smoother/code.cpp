#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        std::vector<std::vector<int>> res (img.size(), std::vector<int>(img[0].size(), 0));

        std::vector<std::pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 0}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        for(int i(0); i < img.size(); i++)
        {
            for(int j(0); j < img[0].size(); j++)
            {
                int neighbors(0);
                int sum(0);
                for(auto dir: dirs)
                {
                    int x(i + dir.first);
                    int y(j + dir.second);
                    if(x >= 0 && x < img.size() && y >= 0 && y < img[0].size())
                    {
                        neighbors++;
                        sum += img[x][y];
                    }
                }
                res[i][j] = sum / neighbors;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> img = {
            {1,1,1},
            {1,0,1},
            {1,1,1}
        };
        std::vector<std::vector<int>> res = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };
        assert(sol.imageSmoother(img) == res);
    }
    {
        std::vector<std::vector<int>> img = {
            {100,200,100},
            {200,50,200},
            {100,200,100},
        };
        std::vector<std::vector<int>> res = {
            {137,141,137},
            {141,138,141},
            {137,141,137},
        };
        assert(sol.imageSmoother(img) == res);
    }
    return 0;
}