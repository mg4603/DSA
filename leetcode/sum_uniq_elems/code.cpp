#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int sumOfUnique(std::vector<int>& nums) {
        std::vector<int> freq(101, 0);
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            int temp1 = ++freq[temp];
            res += temp;
            if(temp1 == 2)
            {
                res -= 2 * temp;
            }
            else if(temp1 > 2)
            {
                res -= temp;
            }

        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,2};
        int res = 4;
        assert(sol.sumOfUnique(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1,1,1};
        int res = 0;
        assert(sol.sumOfUnique(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4,5};
        int res = 15;
        assert(sol.sumOfUnique(nums) == res);
    }
    return 0;
}