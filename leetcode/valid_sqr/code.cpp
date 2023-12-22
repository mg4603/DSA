#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    bool validSquare(std::vector<int>& p1, 
                     std::vector<int>& p2, 
                     std::vector<int>& p3, 
                     std::vector<int>& p4) 
    {
        std::vector<std::vector<int>> pts{p1, p2, p3, p4};
        std::unordered_map<int, int> cnt;

        int side = std::numeric_limits<int>::max();

        for(int i = 0; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                int x = pts[i][0] - pts[j][0];
                int y = pts[i][1] - pts[j][1];

                int z = x * x + y * y;

                side = std::min(side, z);
                cnt[z]++;
            }
        }

        return cnt[side] == 4 && cnt[2 * side] == 2;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> p1 = {0,0};
        std::vector<int> p2 = {1,1};
        std::vector<int> p3 = {1,0};
        std::vector<int> p4 = {0,1};
        bool res = true;
        assert(sol.validSquare(p1, p2, p3, p4) == res);
    }
    {
        std::vector<int> p1 = {1,0};
        std::vector<int> p2 = {-1,0};
        std::vector<int> p3 = {0,1};
        std::vector<int> p4 = {0,-1};
        bool res = true;
        assert(sol.validSquare(p1, p2, p3, p4) == res);
    }
    {
        std::vector<int> p1 = {0,0};
        std::vector<int> p2 = {1,1};
        std::vector<int> p3 = {1,0};
        std::vector<int> p4 = {0,12};
        bool res = false;
        assert(sol.validSquare(p1, p2, p3, p4) == res);
    }
    return 0;
}