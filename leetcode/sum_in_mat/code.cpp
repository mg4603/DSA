#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int matrixSum(std::vector<std::vector<int>>& nums) {
        std::ios::sync_with_stdio(0);
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            std::sort(nums[i].begin(), nums[i].end());
        }

        for(int j = 0; j < nums[0].size(); j++) {
            int temp = 0;
            for(int i = 0; i < nums.size(); i++) {
                temp = std::max(temp, nums[i][j]);
            }
            res += temp;
        }
            
        return res;
    }
};


int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> nums = {{7,2,1}, {6,4,2}, 
                                {6,5,3}, {3,2,1}};
        int res = 15;
        assert(sol.matrixSum(nums) == res);
    }
    return 0;
}