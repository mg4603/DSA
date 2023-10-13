#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
        std::ios_base::sync_with_stdio(0);
        
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];

        for(int i = 1; i < coordinates.size(); i++)
        {
            if(dx * (coordinates[i][1] - coordinates[i - 1][1]) != dy * 
                (coordinates[i][0] - coordinates[i - 1][0]))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> coordinates = {
            {1,2},{2,3},{3,4},{4,5},{5,6},{6,7}
        };
        bool res = true;
        assert(sol.checkStraightLine(coordinates) == res);
    }
    {
        std::vector<std::vector<int>> coordinates = {
            {1,1},{2,2},{3,4},{4,5},{5,6},{7,7}
        };
        bool res = false;
        assert(sol.checkStraightLine(coordinates) == res);
    }
    return 0;
}