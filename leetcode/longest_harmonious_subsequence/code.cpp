#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::map<int, int> num_freq;
        for(int num: nums)
        {
            num_freq[num]++;
        }
        int res(0);
        for(auto pair: num_freq)
        {
            if(num_freq.count(pair.first - 1) == 0)
            {
                continue;
            }
            int temp = pair.second + num_freq[pair.first - 1];
            if(temp > res)
            {
                res = temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,2,2,5,2,3,7};
        int res = 5;
        assert(sol.findLHS(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4};
        int res = 2;
        assert(sol.findLHS(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1,1};
        int res = 0;
        assert(sol.findLHS(nums) == res);
    }
    return 0;
}