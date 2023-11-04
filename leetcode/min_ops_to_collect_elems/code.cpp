#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) 
    {
        std::vector<int> elems(k + 1, 0);
        int count = 0;
        int res = 0;

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] > k)
            {
                res++;
                continue;
            }
            else if(elems[nums[i]] == 0)
            {
                elems[nums[i]] = 1;
                count++;
                res++;
            }
            else
            {
                res++;
            }
            if(count == k)
            {
                break;
            }
            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,1,5,4,2};
        int k = 2;
        int res = 4;
        assert(sol.minOperations(nums, k) == res);
    }
    {
        std::vector<int> nums = {3,1,5,4,2};
        int k = 5;
        int res = 5;
        assert(sol.minOperations(nums, k) == res);
    }
    {
        std::vector<int> nums = {3,2,5,3,1};
        int k = 3;
        int res = 4;
        assert(sol.minOperations(nums, k) == res);
    }
    return 0;
}