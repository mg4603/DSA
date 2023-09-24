#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        int r1x1 = rec1[0];
        int r1x2 = rec1[2];
        int r1y1 = rec1[1];
        int r1y2 = rec1[3];

        int r2x1 = rec2[0];
        int r2x2 = rec2[2];
        int r2y1 = rec2[1];
        int r2y2 = rec2[3];


        if(r2x1 >= r1x2 || r2y1 >= r1y2 || r2y2 <= r1y1 || r2x2 <= r1x1)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> rec1 = {0,0,2,2};
        std::vector<int> rec2 = {1,1,3,3};

        assert(sol.isRectangleOverlap(rec1, rec2) == true);
    }
    {
        std::vector<int> rec1 = {0,0,1,1};
        std::vector<int> rec2 = {1,0,2,1};

        assert(sol.isRectangleOverlap(rec1, rec2) == false);
    }
    {
        std::vector<int> rec1 = {0,0,1,1};
        std::vector<int> rec2 = {2,2,3,3};

        assert(sol.isRectangleOverlap(rec1, rec2) == false);
    }
    return 0;
}