#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isCovered(std::vector<std::vector<int>>& ranges, 
                    int left, int right) 
    {
        std::ios_base::sync_with_stdio(0);
        
        std::vector<int> in_range(52, 0);
        for(int i = 0; i < ranges.size(); i++)
        {
            in_range[ranges[i][0]]++;
            in_range[ranges[i][1] + 1]--;
        }

        for(int i = 1; i < 51; i++)
        {
            in_range[i] += in_range[i - 1];
        }

        for(int i = left; i <= right; i++)
        {
            if(in_range[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> ranges = {{1,2},{3,4},{5,6}};
        int left = 2;
        int right = 5;
        int res = 1;
        assert(sol.isCovered(ranges, left, right) == res);
    }
    {
        std::vector<std::vector<int>> ranges = {{1,10},{10,20}};
        int left = 21;
        int right = 21;
        int res = 0;
        assert(sol.isCovered(ranges, left, right) == res);
    }
    return 0;
}