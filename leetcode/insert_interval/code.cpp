#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(
                                std::vector<std::vector<int>>& intervals, 
                                std::vector<int>& newInterval) 
    {
        std::vector<std::vector<int>> res;
        int n = intervals.size();
        int i = 0;

        while(i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        res.push_back(newInterval);
        while(i < n)
        {
            if(intervals[i][0] > newInterval[1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                if(intervals[i][0] < res.back()[0])
                {
                    res.back()[0] = intervals[i][0];
                }
                if(intervals[i][1] > res.back()[1])
                {
                    res.back()[1] = intervals[i][1];
                }
            }
            i++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> intervals = {{1,3},{6,9}};
        std::vector<int> newInterval = {2,5};
        std::vector<std::vector<int>> res = {{1,5},{6,9}};
        assert(sol.insert(intervals, newInterval) == res);
    }
    {
        std::vector<std::vector<int>> intervals = 
                                        {{1,2},{3,5},{6,7},{8,10},{12,16}};
        std::vector<int> newInterval = {4,8};
        std::vector<std::vector<int>> res = {{1,2},{3,10},{12,16}};
        assert(sol.insert(intervals, newInterval) == res);
    }
    return 0;
}