#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<long long> distance(std::vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++)mp[nums[i]].push_back(i);
        std::vector<long long> res(n, 0LL);

        for(auto it: mp)
        {
            std::vector<int> indices = it.second;
            long long total_sum = 0LL;
            int m = indices.size();
            if(m == 1)continue;
            
            for(int i = 0; i < m; i++)total_sum += indices[i];

            long long preSum = 0LL;
            for(int i = 0; i < m; i++)
            {
                int index = indices[i];
                res[index] += 1LL * index * i;
                res[index] -= (2LL * preSum + index);
                res[index] += total_sum - (1LL * index * (m - i - 1));

                preSum += indices[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,1,1,2};
        std::vector<long long> res = {5,0,3,4,0};
        assert(sol.distance(nums) == res);
    }
    return 0;
}