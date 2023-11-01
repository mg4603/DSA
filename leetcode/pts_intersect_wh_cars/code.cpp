#include <iostream>
#include <assert.h>

#include <numeric>
#include <vector>

class Solution {
public:
    int numberOfPoints(std::vector<std::vector<int>>& nums) 
    {
        std::vector<int> pts(101, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = nums[i][0]; j <= nums[i][1]; j++)
            {
                pts[j] = 1;
            }
        }    
        return std::accumulate(pts.begin(), pts.end(), 0);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> nums = {{3,6},{1,5},{4,7}};
        int res = 7;
        assert(sol.numberOfPoints(nums) == res);
    }
    {
        std::vector<std::vector<int>> nums = {{1,3},{5,8}};
        int res = 7;
        assert(sol.numberOfPoints(nums) == res);
    }
    return 0;
}