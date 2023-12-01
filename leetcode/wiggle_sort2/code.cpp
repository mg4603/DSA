#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    void wiggleSort(std::vector<int>& nums) 
    {
        int n = nums.size();

        if(n <= 1)
        {
            return;
        }

        std::sort(nums.begin(), nums.end());
        std::vector<int> res(n, 0);
        
        int j = n - 1;
        for(int i = 1; i < n; i += 2)
        {
            res[i] = nums[j--];
        }

        for(int i = 0; i < n; i += 2)
        {
            res[i] = nums[j--];
        }
        nums = res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,5,1,1,6,4};
        std::vector<int> res = {1,6,1,5,1,4};
        sol.wiggleSort(nums);
        assert(nums == res);
    }
    {
        std::vector<int> nums = {1,3,2,2,3,1};
        std::vector<int> res = {2,3,1,3,1,2};
        sol.wiggleSort(nums);
        assert(nums == res);
    }
    return 0;
}