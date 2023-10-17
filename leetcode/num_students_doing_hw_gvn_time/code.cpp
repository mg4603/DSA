#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int busyStudent(std::vector<int>& startTime, std::vector<int>& endTime, 
                    int queryTime) {
        
        std::ios_base::sync_with_stdio(0);
        int res = 0;
        int n = startTime.size();
        for(int i = 0; i < n; i++)
        {
            if(queryTime >= startTime[i] && queryTime <= endTime[i])
            {
                res++;
            }
            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> startTime = {1,2,3};
        std::vector<int> endTime = {3,2,7};
        int queryTime = 4;
        int res = 1;
        assert(sol.busyStudent(startTime, endTime, queryTime) == res);
    }
    {
        std::vector<int> startTime = {4};
        std::vector<int> endTime = {4};
        int queryTime = 4;
        int res = 1;
        assert(sol.busyStudent(startTime, endTime, queryTime) == res);
    }
    return 0;
}