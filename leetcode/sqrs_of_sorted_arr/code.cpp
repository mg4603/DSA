#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int i(0);
        while(i < nums.size() && nums[i] < 0)
        {
            i++;
        }

        int j(i--);
        std::vector<int> squares;
        
        while(i >= 0 && j < nums.size())
        {
            if(std::abs(nums[i]) < std::abs(nums[j]))
            {
                squares.push_back(nums[i] * nums[i]);
                i--;
            }
            else
            {
                squares.push_back(nums[j] * nums[j]);
                j++;
            }
        }

        while(i >= 0)
        {
            squares.push_back(nums[i] * nums[i]);
            i--;
        }
        while(j < nums.size())
        {
            squares.push_back(nums[j] * nums[j]);
            j++;
        }
        return squares;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-4,-1,0,3,10};
        std::vector<int> squares = {0,1,9,16,100};
        assert(sol.sortedSquares(nums) == squares);
    }
    {
        std::vector<int> nums = {-7,-3,2,3,11};
        std::vector<int> squares = {4,9,9,49,121};
        assert(sol.sortedSquares(nums) == squares);
    }
    return 0;
}