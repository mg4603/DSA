#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) 
    {
        std::sort(pairs.begin(), pairs.end());

        int res = 0;
        int last = std::numeric_limits<int>::min();

        for(int i = 0; i < pairs.size(); i++)
        {
            if(last < pairs[i][0])
            {
                last = pairs[i][1];
                res++;
            }
            else if(last > pairs[i][1])
            {
                last = pairs[i][1];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> pairs = {{1,2},{2,3},{3,4}};
        int res = 2;
        assert(sol.findLongestChain(pairs) == res);
    }
    {
        std::vector<std::vector<int>> pairs = {{1,2},{7,8},{4,5}};
        int res = 3;
        assert(sol.findLongestChain(pairs) == res);
    }
    return 0;
}