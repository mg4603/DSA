#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        std::vector<int> res;
        int n(nums.size());
        
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        int idx(0);
        for(int i(1); i <= n; i++)
        {
            if(nums[idx] != i)
            {
                res.push_back(i);
            }
            else
            {
                idx++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,3,2,7,8,2,3,1};
        std::vector<int> res = {5, 6};

        assert(sol.findDisappearedNumbers(nums) == res);
    }
    {
        std::vector<int> nums = {1, 1};
        std::vector<int> res = {2};

        assert(sol.findDisappearedNumbers(nums) == res);
    }
    return 0;
}