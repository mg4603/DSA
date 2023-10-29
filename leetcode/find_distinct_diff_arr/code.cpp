#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> distinctDifferenceArray(std::vector<int>& nums) 
    {
        int n = nums.size();
        
        std::unordered_map<int, int> left;
        std::unordered_map<int, int> right;

        for(int i = 0; i < n; i++)
        {
            right[nums[i]]++;
        }
        
        std::vector<int> diff(n, 0);
        for(int i = 0; i < n; i++)
        {
            int temp = nums[i];
            right[temp]--;
            if(right[temp] == 0)
            {
                right.erase(temp);
            }
            left[temp]++;
            diff[i] = left.size() - right.size();
        }
        return diff;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4,5};
        std::vector<int> res = {-3,-1,1,3,5};
        assert(sol.distinctDifferenceArray(nums) == res);
    }
    {
        std::vector<int> nums = {3,2,3,4,2};
        std::vector<int> res = {-2,-1,0,2,3};
        assert(sol.distinctDifferenceArray(nums) == res);
    }
    return 0;
}