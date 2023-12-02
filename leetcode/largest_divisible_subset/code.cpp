#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        int flag = 1;
        if(nums[0] == 1)
        {
            flag = 0;
        }
        else
        {
            nums.insert(nums.begin(), 1);
        }

        int n = nums.size();
        std::vector<std::vector<int>> table(n, std::vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            table[i][0] = 0;
            table[i][1] = i;

            for(int j = i + 1; j < n; j++)
            {
                if(nums[j] % nums[i] == 0 && table[j][0] > table[i][0])
                {
                    table[i][0] = table[j][0];
                    table[i][1] = j;
                }
            }
            table[i][0]++;
        }

        std::vector<int> res;

        int i = 0;
        while(table[i][1] != i)
        {
            res.push_back(nums[i]);
            i = table[i][1];
        }
        res.push_back(nums[i]);

        if(flag)
        {
            res.erase(res.begin());
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3};
        std::vector<int> res = {1, 2};
        assert(sol.largestDivisibleSubset(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,4,8};
        std::vector<int> res = {1,2,4,8};
        assert(sol.largestDivisibleSubset(nums) == res);
    }
    return 0;
}