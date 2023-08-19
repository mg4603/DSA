#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums({3,2,2,3});
        int val(3);
        assert(sol.removeElement(nums, val) == 2);
    }
    {
        std::vector<int> nums({0,1,2,2,3,0,4,2});
        int val(2);
        assert(sol.removeElement(nums, val) == 5);
    }
    return 0;
}