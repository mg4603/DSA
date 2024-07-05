#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minCost(std::string colors, std::vector<int>& neededTime) {
        std::ios::sync_with_stdio(0);
        char last;
        int res = 0;
        int curr = 0;
        int max_time = 0;
        int total_time = 0;
        for(int i = 0; i < colors.size(); i++) {
            if(colors[i] != last) {
                res += (total_time - max_time);
                last = colors[i];
                curr = 1;
                total_time = neededTime[i];
                max_time = neededTime[i];
                continue;
            } else {
                curr++;
                max_time = std::max(max_time, neededTime[i]);
                total_time += neededTime[i];
            }
        }
        res += (total_time - max_time);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string colors = "abaac";
        std::vector<int> neededTime = {1,2,3,4,5};
        int res = 3;
        assert(sol.minCost(colors, neededTime) == res);
    }
    return 0;
}