#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfitAssignment(std::vector<int>& d, 
                            std::vector<int>& p, 
                            std::vector<int>& w) {
        int n = d.size();
        std::vector<std::pair<int, int>> jobs(n);
        for(int i = 0; i < n; i++)
        {
            jobs[i] = std::make_pair(d[i], p[i]);
        }
        std::sort(jobs.begin(), jobs.end());
        std::sort(w.begin(), w.end());
        int j = 0;
        int best = 0;
        int res = 0;
        for(int i = 0; i < w.size(); i++)
        {
            while(j < n && w[i] >= jobs[j].first)
            {
                best = std::max(best, jobs[j++].second);
            }
            res += best;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> difficulty = {2,4,6,8,10};
        std::vector<int> profit = {10,20,30,40,50};
        std::vector<int> worker = {4,5,6,7};
        int res = 100;
        assert(sol.maxProfitAssignment(difficulty, profit, worker) == res);
    }
    return 0;
}