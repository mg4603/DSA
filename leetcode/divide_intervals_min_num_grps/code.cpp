#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        std::ios::sync_with_stdio(0);
        
        std::sort(intervals.begin(), intervals.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for(std::vector<int> interval: intervals)
        {
            if(!q.empty() && q.top() < interval[0])
            {
                q.pop();
            }
            q.push(interval[1]);
        }
        return q.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> intervals = {{5,10},{6,8},
                                                   {1,5},{2,3},
                                                   {1,10}};
        int res = 3;
        assert(sol.minGroups(intervals) == res);
    }
    return 0;
}