#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> length(n, 1);
        std::vector<int> count(n, 1);

        int max_len = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i ; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(length[j] + 1 > length[i])
                    {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }

                    if(length[j] + 1 == length[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            max_len = std::max(max_len, length[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(length[i] == max_len)
            {
                res += count[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,5,4,7};
        int res = 2;
        assert(sol.findNumberOfLIS(nums) == res);
    }
    return 0;
}