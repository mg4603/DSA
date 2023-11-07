#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) 
    {
        int res = 0;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int min_diff = std::numeric_limits<int>::max();

        for(int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while(l < r)
            {
                int temp = nums[i] + nums[l] + nums[r];
                int diff = target - temp;
                if(diff > 0)
                {
                    if(std::abs(diff) < min_diff)
                    {
                        min_diff = std::abs(diff);
                        res = temp;
                    }
                    l++;
                }
                else if(diff < 0)
                {
                    if(std::abs(diff) < min_diff)
                    {
                        min_diff = std::abs(diff);
                        res = temp;
                    }
                    r--;
                }
                else
                {
                    return temp;
                }

            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-1,2,1,-4};
        int target = 1;
        int res = 2;
        assert(sol.threeSumClosest(nums, target) == res);
    }
    {
        std::vector<int> nums = {0,0,0};
        int target = 1;
        int res = 0;
        assert(sol.threeSumClosest(nums, target) == res);
    }
    return 0;
}