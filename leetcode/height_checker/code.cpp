#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        std::ios_base::sync_with_stdio(0);
        std::vector<int> copy_heights(heights.begin(), heights.end());
        std::sort(copy_heights.begin(), copy_heights.end());
        int res = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            if(heights[i] != copy_heights[i])
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
        std::vector<int> heights = {1,1,4,2,1,3};
        int res = 3;
        assert(sol.heightChecker(heights) == res);
    }
    {
        std::vector<int> heights = {5,1,2,3,4};
        int res = 5;
        assert(sol.heightChecker(heights) == res);
    }
    {
        std::vector<int> heights = {1,2,3,4,5};
        int res = 0;
        assert(sol.heightChecker(heights) == res);
    }
    return 0;
}