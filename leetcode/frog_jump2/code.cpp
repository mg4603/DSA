#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxJump(std::vector<int>& stones) {
        std::ios::sync_with_stdio(0);
        if(stones.size() <= 2) {
            return stones.back();
        }

        int res = 0;
        for(int i = 0; i + 2 < stones.size(); i++) {
            res = std::max(res, stones[i + 2] - stones[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> stones = {0,2,5,6,7};
        int res = 5;
        assert(sol.maxJump(stones) == res);
    }
    return 0;
}