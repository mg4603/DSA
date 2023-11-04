#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    void helper(std::vector<std::vector<int>> &res, 
                std::vector<int> &candidates, 
                std::vector<int> &temp, 
                int start, int target)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i = start; i < candidates.size(); i++)
        {
            if(i > start && candidates[i] == candidates[i - 1])continue;
            if(candidates[i] > target)break;
            temp.push_back(candidates[i]);
            helper(res, candidates, temp, i + 1, target - candidates[i]);
            temp.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum2(
                                    std::vector<int>& candidates, 
                                    int target) 
    {
        std::vector<std::vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> temp;
        helper(res, candidates, temp, 0, target);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> candidates = {10,1,2,7,6,1,5};
        int target = 8;
        std::vector<std::vector<int>> res = 
                                        {{1,1,6},{1,2,5},{1,7},{2,6}};
        assert(sol.combinationSum2(candidates, target) == res);
    }
    {
        std::vector<int> candidates = {2,5,2,1,2};
        int target = 5;
        std::vector<std::vector<int>> res = 
                                        {{1,2,2},{5}};

        assert(sol.combinationSum2(candidates, target) == res);
    }
    return 0;
}