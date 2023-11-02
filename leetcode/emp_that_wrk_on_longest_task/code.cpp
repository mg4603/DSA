#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int hardestWorker(int n, std::vector<std::vector<int>>& logs) 
    {
        int prev_end = 0;
        int res = -1;
        int max_time = 0;
        for(int i = 0; i < logs.size(); i++)
        {
            int id = logs[i][0];
            int end_time = logs[i][1];
            int task_time = end_time - prev_end;
            if(task_time > max_time)
            {
                max_time = task_time;
                res = id;
            }
            else if(task_time == max_time && res > id)
            {
                res = id;
            }
            prev_end = end_time;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 10;
        std::vector<std::vector<int>> logs = {
                                    {0,3},{2,5},{0,9},{1,15},};
        int res = 1;
        assert(sol.hardestWorker(n, logs) == res);
    }
    {
        int n = 26;
        std::vector<std::vector<int>> logs = {
                                    {1,1},{3,7},{2,12},{7,17},};
        int res = 3;
        assert(sol.hardestWorker(n, logs) == res);
    }
    {
        int n = 2;
        std::vector<std::vector<int>> logs = {
                                    {0,10},{1,20},};
        int res = 0;
        assert(sol.hardestWorker(n, logs) == res);
    }
    return 0;
}