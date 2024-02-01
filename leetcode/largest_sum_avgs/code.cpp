#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    double largestSumOfAverages(std::vector<int>& nums, int K) {
        int n = nums.size();
        std::vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }

        if(K <= 1)
        {
            return (1.0 * sum[n]) / n;
        }
        if(K >= n)
        {
            return sum[n];
        }

        std::vector<std::vector<double>> table(n + 1, 
                        std::vector<double>(K + 1, 0.0));

        for(int i = 1; i <= n; i++)
        {
            table[i][1] = 1.0 * sum[i] / i;
        }

        for(int k = 2; k <= K; k++)
        {
            for(int i = k; i <= n; i++)
            {
                for(int j = k - 1; j < i ; j++)
                {
                    table[i][k] = std::max(table[i][k], 
                                        table[j][k - 1] + 
                                        1.0 * (sum[i] - sum[j]) / 
                                        (i - j));
                }
            }
        }
        return table[n][K];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {9,1,2,3,9};
        int k = 3;
        double res = 20.0;
        assert(sol.largestSumOfAverages(nums, k) == res);
    }
    return 0;
}