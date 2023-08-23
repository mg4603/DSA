#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

struct IntervalComparator
{
    bool operator()(const std::vector<int> &a, const std::vector<int> &b)
    {
        return a[0] > b[0];
    }
};

using IntervalPriorityQueue = std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, IntervalComparator>;

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        IntervalPriorityQueue pq(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> res;
    
        while(pq.size() > 1)
        {
            std::vector<int> one = pq.top();
            pq.pop();
            std::vector<int> two = pq.top();
            pq.pop();

            std::vector<int> three;
            if(one[1] >= two[0])
            {
                three.push_back(std::min(one[0], two[0]));
                three.push_back(std::max(one[1], two[1]));
                pq.push(three);
            }
            else
            {
                res.push_back(one);
                pq.push(two);
            }
        }
        if(!pq.empty())
        {
            res.push_back(pq.top());
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> vec{{1,3},{2,6},{8,10},{15,18}};
        assert(sol.merge(vec) 
                == (std::vector<std::vector<int>>{std::vector<int>{1,6},
                    std::vector<int>{8,10},std::vector<int>{15,18}}));
    }
    {
        std::vector<std::vector<int>> vec{{1,4},{4,5}};
        assert(sol.merge(vec) 
                == (std::vector<std::vector<int>>{std::vector<int>{1,5}}));
    }
    return 0;
}