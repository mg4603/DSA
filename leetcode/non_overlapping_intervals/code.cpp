#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) 
    {
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end());
        
        int curr = 0;
        int size = 0;

        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] < intervals[curr][1])
            {
                if(intervals[i][1] < intervals[curr][1])
                {
                    curr = i;
                }
                continue;
            }
            size++;
            curr = i;
        }
        return n - size - 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
        int res = 1;
        assert(sol.eraseOverlapIntervals(intervals) == res);
    }
    {
        std::vector<std::vector<int>> intervals = {{1,2},{1,2},{1,2}};
        int res = 2;
        assert(sol.eraseOverlapIntervals(intervals) == res);
    }
    {
        std::vector<std::vector<int>> intervals = {{1,2},{2,3}};
        int res = 0;
        assert(sol.eraseOverlapIntervals(intervals) == res);
    }
    return 0;
}