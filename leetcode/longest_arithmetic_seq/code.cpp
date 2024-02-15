#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int longestArithSeqLength(std::vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
        {
            return n;
        }
        int res = 2;
        std::vector<std::unordered_map<int, int>> table(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int diff = nums[j] - nums[i];
                table[j][diff] = table[i].count(diff)? 
                                        table[i][diff] + 1:2;
                if(table[j][diff] > res)
                {
                    res = table[j][diff];
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
        std::vector<int> nums = {3,6,9,12};
        int res = 4;
        assert(sol.longestArithSeqLength(nums) == res);
    }
    return 0;
}