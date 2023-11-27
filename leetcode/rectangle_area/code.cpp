#include <iostream>
#include <assert.h>

class Solution {
public:
    int computeArea(int ax1, int ay1, 
                    int ax2, int ay2, 
                    int bx1, int by1, 
                    int bx2, int by2) 
    {
        int max_left = std::max(ax1, bx1);
        int min_right = std::min(ax2, bx2);

        int max_bottom = std::max(ay1, by1);
        int min_top = std::min(ay2, by2);

        int area1 = (ay2-ay1) * (ax2-ax1);
        int area2 = (by2-by1) * (bx2-bx1);

        if(max_left > min_right || max_bottom > min_top)
        {
            return area1 + area2;
        }
        return area1 + area2 - ((min_right - max_left) * 
                                (min_top - max_bottom));
    }
};

int main()
{
    Solution sol;
    {
        int ax1 = -3;
        int ay1 = 0;
        int ax2 = 3;
        int ay2 = 4;
        int bx1 = 0;
        int by1 = -1;
        int bx2 = 9;
        int by2 = 2;
        int res = 45;
        assert(sol.computeArea(ax1, ay1, 
                               ax2, ay2, 
                               bx1, by1, 
                               bx2, by2) == res);
    }
    {
        int ax1 = -2;
        int ay1 = -2;
        int ax2 = 2;
        int ay2 = 2;
        int bx1 = -2;
        int by1 = -2;
        int bx2 = 2;
        int by2 = 2;
        int res = 16;
        assert(sol.computeArea(ax1, ay1, 
                               ax2, ay2, 
                               bx1, by1, 
                               bx2, by2) == res);
    }
    return 0;
}