#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> pathInZigZagTree(int label) {
        std::ios::sync_with_stdio(0);
        int levels = std::ceil(std::log2(label + 1));
        std::vector<int> res(levels);

        for(int level = levels - 1; label >= 1; label /= 2, level--) {
            res[level] = label;
            label = (1 << level + 1) - label + (1 << level) - 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int label = 14;
        std::vector<int> res = {1,3,4,14};
        assert(sol.pathInZigZagTree(label) == res);
    }
    return 0;
}