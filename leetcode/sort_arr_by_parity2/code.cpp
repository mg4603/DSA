#include <iostream>
#include <assert.h>

#include <queue>
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
        std::queue<int> odds;
        std::queue<int> evens;
        std::vector<int> res;
        for(int num: nums)
        {
            if(num % 2 == 0)
            {
                evens.push(num);
            }
            else
            {
                odds.push(num);
            }
            while(odds.size() && evens.size())
            {
                res.push_back(evens.front());
                evens.pop();
                res.push_back(odds.front());
                odds.pop();
            }
            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,2,5,7};
        std::vector<int> output = {4,5,2,7};
        assert(sol.sortArrayByParityII(nums) == output);
    }
    {
        std::vector<int> nums = {2,3};
        std::vector<int> output = {2,3};
        assert(sol.sortArrayByParityII(nums) == output);
    }
    return 0;
}