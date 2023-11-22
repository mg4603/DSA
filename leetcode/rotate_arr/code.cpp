#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k % n;

        std::vector<int> temp;
        for(int i = n - k; i < n; i++)
        {
            temp.push_back(nums[i]);
        }    

        for(int i = n - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }
        
        for(int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4,5,6,7};
        int k = 3;
        std::vector<int> res = {5,6,7,1,2,3,4};
        sol.rotate(nums, k);
        assert(nums == res);
    }
    {
        std::vector<int> nums = {-1,-100,3,99};
        int k = 2;
        std::vector<int> res = {3,99,-1,-100};
        sol.rotate(nums, k);
        assert(nums == res);
    }
    return 0;
}