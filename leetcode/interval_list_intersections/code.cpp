#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(
                        std::vector<std::vector<int>>& firstList, 
                        std::vector<std::vector<int>>& secondList) {
        std::vector<std::vector<int>> res;
        int n = firstList.size();
        int m = secondList.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            int low = std::max(firstList[i][0], secondList[j][0]);
            int high = std::min(firstList[i][1], secondList[j][1]);
            if(low <= high) {
                res.push_back({low, high});
            }

            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> firstList = {{1,3},{5,9}};
        std::vector<std::vector<int>> secondList = {};
        std::vector<std::vector<int>> res = {};
        assert(sol.intervalIntersection(firstList, secondList) == res);
    }
    return 0;
}