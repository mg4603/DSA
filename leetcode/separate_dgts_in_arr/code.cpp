#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(0);
        std::vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            std::string temp = std::to_string(nums[i]);
            for(int j = 0; j < temp.size(); j++)
            {
                res.push_back(temp[j] - '0');
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {13,25,83,77};
        std::vector<int> res = {1,3,2,5,8,3,7,7};
        assert(sol.separateDigits(nums) == res);
    }
    {
        std::vector<int> nums = {7,1,3,9};
        std::vector<int> res = {7,1,3,9};
        assert(sol.separateDigits(nums) == res);
    }
    return 0;
}