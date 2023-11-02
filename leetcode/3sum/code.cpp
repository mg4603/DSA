#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++)
        {
            if(nums[i] > 0)
            {
                break;
            }
            else if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                int l = i + 1;
                int r = n - 1;

                while(l < r)
                {
                    if(nums[i] + nums[l] + nums[r] > 0)
                    {
                        r--;
                    }
                    else if(nums[i] + nums[l] + nums[r] < 0)
                    {
                        l++;
                    }
                    else
                    {
                        std::vector<int> temp{nums[i], nums[l], nums[r]};
                        res.push_back(temp);
                        while(l < r && nums[l] == temp[1])
                        {
                            l++;
                        }
                        while(l  < r && nums[r] == temp[2])
                        {
                            r--;
                        }
                    }
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
        std::vector<int> nums = {-1,0,1,2,-1,-4};
        std::vector<std::vector<int>> res = {{-1,-1,2},{-1,0,1}};
        assert(sol.threeSum(nums) == res);
    }
    {
        std::vector<int> nums = {0,1,1};
        std::vector<std::vector<int>> res = {};
        assert(sol.threeSum(nums) == res);
    }
    {
        std::vector<int> nums = {0,0,0};
        std::vector<std::vector<int>> res = {{0,0,0}};
        assert(sol.threeSum(nums) == res);
    }
    return 0;
}