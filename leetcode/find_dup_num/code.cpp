#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) 
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while(l < r)
        {
            int mid = (l + r) / 2;

            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] <= mid)
                {
                    cnt++;
                }
            }


            if(cnt <= mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }


        }

        return l; 
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,4,2,2};
        int res = 2;
        assert(sol.findDuplicate(nums) == res);
    }
    {
        std::vector<int> nums = {3,1,3,4,2};
        int res = 3;
        assert(sol.findDuplicate(nums) == res);
    }
    return 0;
}