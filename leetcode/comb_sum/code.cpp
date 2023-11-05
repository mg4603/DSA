#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    void helper(std::vector<std::vector<int>> &res, 
                std::vector<int> &candidates, int target, 
                std::vector<int> temp, int start)
    {

        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        if(target < candidates[0])
        {
            return;
        }

        if(start == candidates.size())
        {
            return;
        }

        helper(res, candidates, target, temp, start + 1);

        temp.push_back(candidates[start]);
        helper(res, candidates, target - candidates[start], temp, start);
        temp.pop_back();        
    
    }
public:
    std::vector<std::vector<int>> combinationSum(
                                    std::vector<int>& candidates, 
                                    int target) 
    {
        std::vector<std::vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
        helper(res, candidates, target, {}, 0);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> candidates = {2,3,6,7};
        int target = 7;
        std::vector<std::vector<int>> res = {{7}, {2,2,3},};
        assert(sol.combinationSum(candidates, target) == res);
    }
    {
        std::vector<int> candidates = {2,3,5};
        int target = 8;
        std::vector<std::vector<int>> res = {{3,5},{2,3,3},{2,2,2,2},};
        assert(sol.combinationSum(candidates, target) == res);
    }
    {
        std::vector<int> candidates = {2};
        int target = 1;
        std::vector<std::vector<int>> res = {};
        assert(sol.combinationSum(candidates, target) == res);
    }
    return 0;
}