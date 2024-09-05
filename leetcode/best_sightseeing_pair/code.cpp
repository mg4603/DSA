#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxScoreSightseeingPair(std::vector<int>& values) {
        std::ios::sync_with_stdio(0);
        int n = values.size();

        int res = 0, max_val = 0;
        for(int &val: values) {
            res = std::max(res, val + max_val);
            max_val = std::max(max_val, val) - 1;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> values = {8,1,5,2,6};
        int res = 11;
        assert(sol.maxScoreSightseeingPair(values) == res);
    }
    return 0;
}