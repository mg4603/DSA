#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>
#include <cmath>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 2)
        {
            return 0;
        }
        if(n == 2)
        {
            return std::abs(nums[0] - nums[1]);
        }

        int largest_ele = std::numeric_limits<int>::min();
        int smallest_ele = std::numeric_limits<int>::max();

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > largest_ele)
            {
                largest_ele = nums[i];
            }
            if(nums[i] < smallest_ele)
            {
                smallest_ele = nums[i];
            }
        }
        int bucket_size = std::ceil(static_cast<float>(largest_ele - 
                                                smallest_ele) / (n - 1));

        if(bucket_size == 0)
        {
            return 0;
        }
        
        std::vector<int> bucket_max(n, std::numeric_limits<int>::min());
        std::vector<int> bucket_min(n, std::numeric_limits<int>::max());

        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            int bucket_no = (num - smallest_ele)/bucket_size;

            if(bucket_max[bucket_no] < num)
            {
                bucket_max[bucket_no] = num;
            }
            if(bucket_min[bucket_no] > num)
            {
                bucket_min[bucket_no] = num;
            }
        }

        int res = bucket_size;

        int prev_max = bucket_max[0];

        for(int i = 1; i < n; i++)
        {
            int temp = bucket_min[i];

            if(temp == std::numeric_limits<int>::max())continue;

            if(temp - prev_max > res)
            {
                res = temp - prev_max;
            }
            prev_max = bucket_max[i];
        }
        return res;
    }  
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,6,9,1};
        int res = 3;
        assert(sol.maximumGap(nums) == res);
    }
    {
        std::vector<int> nums = {10};
        int res = 0;
        assert(sol.maximumGap(nums) == res);
    }
    return 0;
}