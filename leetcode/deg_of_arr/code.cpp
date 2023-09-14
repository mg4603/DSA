#include <iostream>
#include <assert.h>

#include <limits>
#include <vector>
#include <map>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::map<int, std::vector<int>> table;

        int idx(0);
        int degree(0);
        for(int num: nums)
        {
            if(table.count(num) == 0)
            {
                table[num] = std::vector<int>({1, idx, idx});

            }    
            else
            {
                table[num][0]++;
                table[num][2] = idx;
                
            }
            if(table[num][0] > degree)
            {
                degree = table[num][0];
            }
            idx++;
        }
        int res(std::numeric_limits<int>::max());
        for(auto row: table)
        {
            if(row.second[0] == degree && row.second[2] - row.second[1] < res)
            {
                res = row.second[2] - row.second[1] + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2,3,1};
        int res = 2;
        assert(sol.findShortestSubArray(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,2,3,1,4,2};
        int res = 6;
        assert(sol.findShortestSubArray(nums) == res);
    }
    return 0;
}