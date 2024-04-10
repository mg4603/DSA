#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        std::ios::sync_with_stdio(0);
        int n = chalk.size();

        long long pre_sum = std::accumulate(chalk.begin(), 
                                    chalk.end(), 0LL);

        k %= pre_sum;

        for(int i = 0; i < n; i++)
        {
            if(chalk[i] > k)return i;
            k -= chalk[i];
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> chalk = {5,1,5};
        int k = 22;
        int res = 0;
        assert(sol.chalkReplacer(chalk, k) == res);
    }
    return 0;
}