#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

class Solution {
public:
    long long minimumRemoval(std::vector<int>& beans) {
        std::sort(beans.begin(), beans.end());
        long long sum = std::accumulate(beans.begin(), 
                                        beans.end(), 0LL);
        long long n = beans.size();
        long long res = std::numeric_limits<long long>::max();

        for(int i = 0; i < n; i++)
        {
            res = std::min(res, sum - (n - i) * beans[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> beans = {4,1,6,5};
        int res = 4;
        assert(sol.minimumRemoval(beans) == res);
    }
    return 0;
}