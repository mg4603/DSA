#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumBags(std::vector<int>& capacity, 
                std::vector<int>& rocks, int additionalRocks) {
        std::ios::sync_with_stdio(0);
        int n = capacity.size();
        for(int i = 0; i < n; i++) {
            capacity[i] -= rocks[i];
        }
        std::sort(capacity.begin(), capacity.end());
        int res = 0;
        for(; res < n; res++){
            if(res > 0)capacity[res] += capacity[res - 1];
            if(capacity[res] > additionalRocks)return res;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> capacity = {2,3,4,5};
        std::vector<int> rocks = {1,2,4,4};
        int additionalRocks = 2;
        int res = 3;
        assert(sol.maximumBags(capacity, rocks, additionalRocks) == res);
    }
    return 0;
}