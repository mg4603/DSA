#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<std::string> res(score.size());
        std::vector<int> sorted_scores(score.begin(), score.end());
        std::sort(sorted_scores.begin(), sorted_scores.end(), std::greater<int>());
        std::map<int, int> score_idx;
        std::map<int, std::string> rank_mp = {
            {0, "Gold Medal"},
            {1, "Silver Medal"},
            {2, "Bronze Medal"}
        };

        for(int i(0); i < score.size(); i++)
        {
            score_idx[score[i]] = i;
        }

        for(int i(0); i < sorted_scores.size(); i++)
        {
            if(rank_mp.count(i))
            {
                res[score_idx[sorted_scores[i]]] = rank_mp[i];
            }
            else
            {
                res[score_idx[sorted_scores[i]]] = std::to_string(i+1);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> score = {5,4,3,2,1};
        std::vector<std::string> res = {"Gold Medal","Silver Medal",
                            "Bronze Medal","4","5"};
        assert(sol.findRelativeRanks(score) == res);
    }
    {
        std::vector<int> score = {10,3,8,9,4};
        std::vector<std::string> res = {"Gold Medal","5","Bronze Medal",
                            "Silver Medal","4"};
        assert(sol.findRelativeRanks(score) == res);
    }
    return 0;
}