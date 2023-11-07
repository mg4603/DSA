#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        
        int n = nums.size();
        int i = 1;
        int j = 1;

        int cnt = 1;
        while(i < n && j < n)
        {
            if(nums[j] == nums[j - 1])
            {
                cnt++;
                if(cnt <= 2)
                {
                    nums[i++] = nums[j++];
                }
                else
                {
                    j++;
                }
            }
            else
            {
                nums[i++] = nums[j++];
                cnt = 1;
            }
        }   
        return i; 
    }
};


int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,1,2,2,3};
        int k = 5;
        std::vector<int> res = {1,1,2,2,3};
        sol.removeDuplicates(nums);
        assert(k == res.size());
        for (int i = 0; i < k; i++) {
            assert(nums[i] == res[i]);
        }
    }
    {
        std::vector<int> nums = {0,0,1,1,1,1,2,3,3};
        int k = 7;
        std::vector<int> res = {0,0,1,1,2,3,3};
        sol.removeDuplicates(nums);
        assert(k == res.size());
        for (int i = 0; i < k; i++) {
            assert(nums[i] == res[i]);
        }
    }
    return 0;
}