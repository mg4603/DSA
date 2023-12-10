#include <iostream>
#include <assert.h>

#include <vector>
#include <map>
#include <algorithm>

class Solution {
    int binSearch(std::vector<std::vector<int>> &intervals, 
                  int i, int n)
    {
        if(intervals[n-1][0] < intervals[i][1])return -1;

        int l = i + 1;
        int r = n - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(intervals[mid][0] >= intervals[i][1])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
public:
    std::vector<int> findRightInterval(
                        std::vector<std::vector<int>>& intervals) 
    {
        int n = intervals.size();
        std::map<std::vector<int>, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[intervals[i]] = i;
        }

        std::sort(intervals.begin(), intervals.end());

        std::vector<int> res(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(intervals[i][0] == intervals[i][1])
            {
                res[mp[intervals[i]]] = mp[intervals[i]];
                continue;
            }

            int pos = binSearch(intervals, i, n);
            if(pos == -1)
            {
                res[mp[intervals[i]]] = -1;
                continue;
            }
            res[mp[intervals[i]]] = mp[intervals[pos]];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> intervals = {{1,2}};
        std::vector<int> res = {-1};
        assert(sol.findRightInterval(intervals) == res);
    }
    
    return 0;
}