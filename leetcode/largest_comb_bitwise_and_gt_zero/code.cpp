#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        for(int i = 1; i <= 1e7; i <<= 1) {
            int curr = 0;
            for(int &num: candidates) {
                curr += (num & i) > 0;
            }
            res = std::max(res, curr);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> candidates = {16,17,71,62,12,24,14};
        int res = 4;
        assert(sol.largestCombination(candidates) == res);
    }
    return 0;
}