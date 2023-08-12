#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    // std::vector<int> twoSum(std::vector<int>& nums, int target) {
    //     for(int i(0); i < nums.size(); i++)
    //     {
    //         for(int j(i + 1); j < nums.size(); j++)
    //         {
    //             if(nums[i] + nums[j] == target)
    //             {
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {0, 0};
    // }
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> num_idx;
        int idx(0);
        for(int num: nums)
        {
            num_idx[num] = idx;
            idx++;
        }
        for(int i(0); i < nums.size(); i++)
        {
            if(num_idx.count(target - nums[i]) != 0 && num_idx[target - nums[i]] != i)
            {
                return {i, num_idx[target-nums[i]]};
            }
        }
        return {0, 0};
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> case1 = {2,7,11,15};
        assert(sol.twoSum(case1, 9) == std::vector<int>({0, 1}));

    }
    {
        std::vector<int> case2 = {3,2,4};
        assert(sol.twoSum(case2, 6) == std::vector<int>({1, 2}));
    }
    {
        std::vector<int>case3 = {3,3};
        assert(sol.twoSum(case3, 6) == std::vector<int>({0, 1}));
    }
    return 0;
}