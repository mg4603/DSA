#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        
        int n = nums.size();
        int min_n = nums[0];
        int max_n = nums[0];

        for(int i = 0; i < n; i++){
            min_n = std::min(min_n, nums[i]);
            max_n = std::max(max_n, nums[i]);
        }

        int offset = std::abs(min_n);

        std::vector<int> cnt(std::abs(max_n) + 
                            std::abs(min_n) + 1, 0);
        for(int i = 0; i < n; i++)
        {
            cnt[nums[i] + offset]++;
        }

        int j = 0;
        for(int i = 0; i < cnt.size(); i++)
        {
            while(cnt[i]--)
            {
                nums[j++] = i - offset;
            }
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,2,3,1};
        std::vector<int> res = {1,2,3,5};
        assert(sol.sortArray(nums) == res);
    }
    return 0;
}