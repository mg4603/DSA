#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int mostFrequentEven(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;

        int most_freq = 0;
        int res = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            if(temp % 2 == 0)
            {
                int cnt = ++mp[temp];
                if(cnt > most_freq)
                {
                    res = temp;;
                    most_freq = cnt;
                }
                else if(cnt == most_freq)
                {
                    if(temp < res)
                    {
                        res = temp;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,1,2,2,4,4,1};
        int res = 2;
        assert(sol.mostFrequentEven(nums) == res);
    }
    {
        std::vector<int> nums = {4,4,4,9,2,4};
        int res = 4;
        assert(sol.mostFrequentEven(nums) == res);
    }
    {
        std::vector<int> nums = {29,47,21,41,13,37,25,7};
        int res = -1;
        assert(sol.mostFrequentEven(nums) == res);
    }
    return 0;
}