#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numberOfArrays(std::vector<int>& differences, 
                        int lower, 
                        int upper) {
        std::ios::sync_with_stdio(0);
        int n = differences.size();
        long long range_lower = 0LL;
        long long range_upper = 0LL;

        long long running_sum = 0LL;
        for(int i = 0; i < n; i++)
        {
            running_sum += differences[i];
            range_lower = std::min(range_lower, running_sum);
            range_upper = std::max(range_upper, running_sum);
        }
        int res = (upper - lower + 1) - (range_upper - range_lower);
        return res < 0 ? 0 : res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> differences = {1,-3,4};
        int lower = 1;
        int upper = 6;
        int res = 2;
        assert(sol.numberOfArrays(differences, lower, upper) == res);
    }
    return 0;
}