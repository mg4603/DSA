#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, 
                                          int target) 
    {
        std::ios_base::sync_with_stdio(0);
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> res;
        int n = nums.size();

        for(int i = 0; i < n - 3; i++)
        {
            for(int j = i + 1; j < n - 2; j++)
            {
                int new_target = target - nums[i];
                int l = j + 1;
                int r = n - 1;
                while(l < r)
                {
                    long long temp = static_cast<long long>(nums[j]) + 
                                     nums[l] + nums[r];
                    
                    if(temp > new_target)
                    {
                        r--;
                    }
                    else if(temp < new_target)
                    {
                        l++;
                    }
                    else
                    {
                            res.push_back({nums[i], nums[j], 
                                           nums[l], nums[r]});

                            int leftIdx = l;
                            int rightIdx = r;
                            while(l < r && nums[l] == nums[leftIdx])
                            {
                                l++;
                            }
                            while(l < r && nums[r] == nums[rightIdx])
                            {
                                r--;
                            }
                    }
                }
                while(j + 1 < n && nums[j] == nums[j+1])
                {
                    j++;
                }
            }
            while(i + 1 < n && nums[i] == nums[i+1])
            {
                i++;
            }
        }  
        return res;  
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,0,-1,0,-2,2};
        int target = 0;
        std::vector<std::vector<int>> res = {{-2,-1,1,2},{-2,0,0,2},
                                             {-1,0,0,1}};
        assert(sol.fourSum(nums, target) == res);
    }
    {
        std::vector<int> nums = {2,2,2,2,2};
        int target = 8;
        std::vector<std::vector<int>> res = {{2,2,2,2}};
        assert(sol.fourSum(nums, target) == res);
    }
    return 0;
}