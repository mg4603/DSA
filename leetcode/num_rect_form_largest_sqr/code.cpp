#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int countGoodRectangles(std::vector<std::vector<int>>& rectangles) 
    {
        int longest_side = 0;
        std::unordered_map<int, int> mp;
        for(int i = 0; i < rectangles.size(); i++)
        {
            int side = std::min(rectangles[i][0], rectangles[i][1]);
            mp[side]++;
            if(side > longest_side)
            {
                longest_side = side;
            }
        }
        return mp[longest_side];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> rectangles = {
            {5,8},{3,9},{5,12},{16,5}};
        int res = 3;
        assert(sol.countGoodRectangles(rectangles) == res);
    }
    {
        std::vector<std::vector<int>> rectangles = {
            {2,3},{3,7},{4,3},{3,7}};
        int res = 3;
        assert(sol.countGoodRectangles(rectangles) == res);
    }
    return 0;
}