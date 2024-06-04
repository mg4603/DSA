#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, 
                        std::vector<std::vector<int>>& queries) {
        int evenSum = 0;
        for(int &num: nums) {
            if(num % 2 == 0)evenSum += num;
        }
        std::vector<int> res;
        for(std::vector<int> &q: queries) {
            int idx = q[1];
            int val = q[0];

            if(nums[idx] % 2 == 0) {
                evenSum -= nums[idx];
            }

            nums[idx] += val;

            if(nums[idx] % 2 == 0) {
                evenSum += nums[idx];
            }
            res.push_back(evenSum);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,4};
        std::vector<std::vector<int>> queries = {{1,0},{-3,1},
                                                 {-4,0},{2,3}};
        std::vector<int> res = {8,6,2,4};
        assert(sol.sumEvenAfterQueries(nums, queries) == res);
    }
    return 0;
}