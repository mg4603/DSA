#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        int longest_contiguous_seq(1);
        int current_contiguous_seq_len(1);
        for(int i(1); i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                current_contiguous_seq_len++;
            }
            else
            {
                if(longest_contiguous_seq < current_contiguous_seq_len)
                {
                    longest_contiguous_seq = current_contiguous_seq_len;
                }
                current_contiguous_seq_len = 1;
            }
        }
        return (longest_contiguous_seq < current_contiguous_seq_len)? 
            current_contiguous_seq_len: longest_contiguous_seq;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,5,4,7};
        assert(sol.findLengthOfLCIS(nums) == 3);
    }
    {
        std::vector<int> nums = {2,2,2,2,2};
        assert(sol.findLengthOfLCIS(nums) == 1);
    }
    return 0;
}