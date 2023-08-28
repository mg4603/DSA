#include <iostream>
#include <assert.h>

#include <map>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int> num_freq;
        for(int num: nums)
        {
            num_freq[num]++;
            if(num_freq[num] > nums.size() / 2)
            {
                return num;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3, 2, 3};
        assert(sol.majorityElement(nums) == 3);
    }
    {
        std::vector<int> nums = {2,2,1,1,1,2,2};
        assert(sol.majorityElement(nums) == 2);
    }
    return 0;
}