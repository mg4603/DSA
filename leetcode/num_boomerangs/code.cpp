#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>
#include <cmath>

class Solution {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points) 
    {
        std::unordered_map<double, int> mp;
        int n = points.size();

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)continue;
                double dist = std::pow(points[j][0] - 
                                points[i][0], 2) + 
                                    std::pow(points[j][1] - 
                                        points[i][1], 2);
                mp[dist]++;
            }
            for(auto it: mp)
            {
                int temp = it.second;
                res += temp * (temp - 1);
            }
            mp.clear();
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> points = {{0,0},{1,0},{2,0}};
        int res = 2;
        assert(sol.numberOfBoomerangs(points) == res);
    }
    {
        std::vector<std::vector<int>> points = {{1,1},{2,2},{3,3}};
        int res = 2;
        assert(sol.numberOfBoomerangs(points) == res);
    }
    {
        std::vector<std::vector<int>> points = {{1, 1}};
        int res = 0;
        assert(sol.numberOfBoomerangs(points) == res);
    }
    return 0;
}