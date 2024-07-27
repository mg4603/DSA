#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int fn(std::vector<int> &pos, int x, int y) {
        int dist = 0;
        if((x < 0 && pos[0] < 0) || x > 0 && pos[0] > 0) {
            dist += std::abs(pos[0] - x);
        }else {
            dist += std::abs(pos[0]) + std::abs(x);
        }

        if((y < 0 && pos[1] < 0) || y > 0 && pos[1] > 0) {
            dist += std::abs(pos[1] - y);
        }else {
            dist += std::abs(pos[1]) + std::abs(y);
        }
        return dist;
    }
public:
    bool escapeGhosts(std::vector<std::vector<int>>& ghosts, 
                        std::vector<int>& target) {
        std::ios::sync_with_stdio(0);
        int dist = fn(target, 0, 0);
        for(auto &ghost: ghosts) {
            if(fn(ghost, target[0], target[1]) <= dist)return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> ghosts = {{1,0},{0,3}};
        std::vector<int> target = {0,1};
        bool res = true;
        assert(sol.escapeGhosts(ghosts, target) == res);
    }
    return 0;
}