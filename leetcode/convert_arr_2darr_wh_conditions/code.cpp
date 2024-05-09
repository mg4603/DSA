#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<int>> findMatrix(
                            std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::map<int, int> mp;
        int max_freq = 0;
        for(int num: nums)
        {
            max_freq = std::max(max_freq, ++mp[num]);
        }

        std::vector<std::vector<int>> res(max_freq);
        for(auto it: mp)
        {
            for(int i = 0; i < it.second; i++)
            {
                res[i].push_back(it.first);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,4,1,2,3,1};

        std::vector<std::vector<int>> res = {{1,2,3,4},{1,3},{1}};
        assert(sol.findMatrix(nums) == res);
    }
    return 0;
}