#include <iostream>
#include <assert.h>

#include <vector>
#include <list>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, 
                        int limit) {
        std::list<int> minList;
        std::list<int> maxList;

        int n = nums.size();

        int res = 1;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            while(minList.size() && 
                    minList.back() > nums[i])
            {
                minList.pop_back();
            }
            minList.push_back(nums[i]);

            while(maxList.size() && 
                    maxList.back() < nums[i])
            {
                maxList.pop_back();
            }
            maxList.push_back(nums[i]);

            while(std::abs(maxList.front() - 
                            minList.front()) > limit)
            {
                if(minList.front() == nums[j])minList.pop_front();
                if(maxList.front() == nums[j])maxList.pop_front();
                j++;
            }
            res = std::max(res, i - j + 1);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {10,1,2,4,7,2};
        int limit = 5;
        int res = 4;
        assert(sol.longestSubarray(nums, limit) == res);
    }
    return 0;
}