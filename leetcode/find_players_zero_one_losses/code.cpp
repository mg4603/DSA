#include <iostream>
#include <assert.h>

#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> findWinners(
                        std::vector<std::vector<int>>& matches) {
        std::ios::sync_with_stdio(0);
        std::vector<int> losses(1e5+1, -1);
        int xmin = INT_MAX;
        int xmax = 0;        
        for(std::vector<int> &match: matches) {
            xmax = std::max(xmax, match[0]);
            xmax = std::max(xmax, match[1]);

            xmin = std::min(xmin, match[0]);
            xmin = std::min(xmin, match[1]);

            if(losses[match[0]] == -1) {
                losses[match[0]] = 0;
            }

            if(losses[match[1]] == -1) {
                losses[match[1]] = 1;
            } else {
                losses[match[1]]++;
            }

        }

        std::vector<std::vector<int>> res(2);
        for(int i = xmin; i <= xmax; i++) {
            if(losses[i] == 0)res[0].push_back(i);
            else if(losses[i] == 1)res[1].push_back(i);
        }
        std::sort(res[0].begin(), res[0].end());
        std::sort(res[1].begin(), res[1].end());
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matches = {
                            {1,3},{2,3},{3,6},{5,6},{5,7},
                            {4,5},{4,8},{4,9},{10,4},{10,9}};
        std::vector<std::vector<int>> res = {{1,2,10},
                                             {4,5,7,8}};
        assert(sol.findWinners(matches) == res);
    }
    return 0;
}