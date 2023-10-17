#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int minStartValue(std::vector<int>& nums) {
        long long res = 0;
        int min_val = std::numeric_limits<int>::max();
        for(int i = 0; i < nums.size(); i++)
        {
            res += nums[i];
            if(res < min_val)
            {
                min_val = res;
            }
        }
        if(min_val >= 1)
        {
            return 1;
        }
        return (-min_val) + 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {-3,2,-3,4,2};
        int res = 5;
        assert(sol.minStartValue(arr) == res);
    }
    {
        std::vector<int> arr = {1,2};
        int res = 1;
        assert(sol.minStartValue(arr) == res);
    }
    {
        std::vector<int> arr = {1,-2,-3};
        int res = 5;
        assert(sol.minStartValue(arr) == res);
    }
    return 0;
}