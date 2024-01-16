#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) 
    {
        int n = nums.size();
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        std::vector<int> table(1 << n, -1);
        table[0] = 0;

        if(total % k)return false;
        int partition = total / k;

        for(int mask = 0; mask < (1 << n); mask++)
        {
            if(table[mask] == -1)continue;
            for(int i = 0; i < n; i++)
            {
                if(!(mask&(1 << i)) && table[mask] + nums[i] <= partition)
                {
                    table[mask | (1 << i)] = (table[mask] + nums[i]) % partition;
                }
            }
        }
        return table[(1 << n)-1] == 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,3,2,3,5,2,1};
        int k = 4;
        bool res = true;
        assert(sol.canPartitionKSubsets(nums, k) == res);
    }
    return 0;
}