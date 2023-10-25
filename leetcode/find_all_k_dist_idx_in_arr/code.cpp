#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> findKDistantIndices(std::vector<int>& nums, 
                                         int key, int k) 
    {
        std::ios_base::sync_with_stdio(0);
        int n = nums.size();
        std::vector<int> res;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != key)continue;
            int start = std::max(i - k, 0);
            if(res.size() != 0)
            {
                start = std::max(start, res.back() + 1);
            }
            for(int j = start; j <= (i + k) && j < n; j++)
            {
                res.push_back(j);
            }

        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,4,9,1,3,9,5};
        int key = 9;
        int k = 1;
        std::vector<int> res = {1,2,3,4,5,6};
        assert(sol.findKDistantIndices(nums, key, k) == res);
    }
    {
        std::vector<int> nums = {2,2,2,2,2};
        int key = 2;
        int k = 2;
        std::vector<int> res = {0,1,2,3,4};
        assert(sol.findKDistantIndices(nums, key, k) == res);
    }
    return 0;
}