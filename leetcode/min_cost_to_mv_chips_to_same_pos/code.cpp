#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minCostToMoveChips(std::vector<int>& position) {
        int odd_pos = 0;
        int even_pos = 0;
        for(int i = 0; i < position.size(); i++)
        {
            if(position[i] % 2 == 0)
            {
                even_pos ++;
            }
            else
            {
                odd_pos++;
            }
        }
        return std::min(odd_pos, even_pos);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> position = {1,2,3};
        int res = 1;
        assert(sol.minCostToMoveChips(position) == res);
    }
    {
        std::vector<int> position = {2,2,2,3,3};
        int res = 2;
        assert(sol.minCostToMoveChips(position) == res);
    }
    {
        std::vector<int> position = {1,1000000000};
        int res = 1;
        assert(sol.minCostToMoveChips(position) == res);
    }
    return 0;
}