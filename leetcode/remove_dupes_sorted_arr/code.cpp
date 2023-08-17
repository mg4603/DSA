#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> vec({1,1,2});
        assert(sol.removeDuplicates(vec) == 2);
    }
    
    {
        std::vector<int> vec({0,0,1,1,1,2,2,3,3,4});
        assert(sol.removeDuplicates(vec) == 5);
    }
    return 0;
}