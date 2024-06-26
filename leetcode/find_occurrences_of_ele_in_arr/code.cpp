#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> occurrencesOfElement(std::vector<int>& nums, 
                                std::vector<int>& queries, int x) {
        std::ios::sync_with_stdio(0);
        std::vector<int> pos;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != x)continue;
            pos.push_back(i);
        }

        int n = queries.size();
        std::vector<int> res(n, -1);
        for(int i = 0; i < n; i++) {
            if(queries[i] > pos.size())continue;
            res[i] = pos[queries[i] - 1];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,1,7};
        std::vector<int> queries = {1,3,2,4};
        int x = 1;
        std::vector<int> res = {0,-1,2,-1};
        assert(sol.occurrencesOfElement(nums, queries, x) == res);
    }
    return 0;
}