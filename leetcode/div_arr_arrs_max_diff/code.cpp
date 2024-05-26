#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> divideArray(
                        std::vector<int>& nums, int k) {
        std::ios::sync_with_stdio(0);
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 3) {
            if(nums[i + 2] - nums[i] <= k) {
                res.push_back({nums[i], nums[i + 1], nums[i + 2]});
            }else {
                res.clear();
                return res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,4,8,7,9,3,5,1};
        int k = 2;
        std::vector<std::vector<int>> res = {{1,1,3},{3,4,5},
                                             {7,8,9}};
        assert(sol.divideArray(nums, k) == res);
    }
    return 0;
}