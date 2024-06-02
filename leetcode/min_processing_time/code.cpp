#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int minProcessingTime(std::vector<int>& processorTime, 
                            std::vector<int>& tasks) {
        std::ios::sync_with_stdio(0);
        std::sort(processorTime.begin(), processorTime.end());
        std::sort(tasks.begin(), tasks.end(), std::greater<int>());
        int res = 0;
        for(int i = 0; i < processorTime.size(); i++) {
            res = std::max(res, processorTime[i] + tasks[i * 4]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> processorTime = {8,10};
        std::vector<int> tasks = {2,2,3,1,8,7,4,5};
        int res = 16;
        assert(sol.minProcessingTime(processorTime, tasks) == res);
    }
    return 0;
}