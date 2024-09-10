#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> maxScoreIndices(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        std::vector<int> suffix(n + 1, 0);

        for(int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + (nums[i - 1] == 0);
            suffix[n - i] = suffix[n - i + 1] + (nums[n - i] == 1);
        }
        std::vector<int> scores(n + 1, 0);
        int max_score = 0;
        for(int i = 0; i < n + 1; i++) {
            scores[i] = prefix[i] + suffix[i];
            max_score = std::max(max_score, scores[i]);
        }
        std::vector<int> res;
        for(int i = 0; i < n + 1; i++) {
            if(scores[i] == max_score)res.push_back(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {0,0,1,0};
        std::vector<int> res = {2, 4};
        assert(sol.maxScoreIndices(nums) == res);
    }
    return 0;
}