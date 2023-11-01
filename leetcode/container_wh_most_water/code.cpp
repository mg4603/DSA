#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) 
    {
        int start = 0;
        int end = height.size() - 1;
        int res = (end - start) * std::min(height[start], height[end]);
        while(start < end)
        {
            int temp = (end - start) * std::min(height[start], height[end]);
            if(temp > res)
            {
                res = temp;
            }

            if(height[start] > height[end])
            {
                end--;
            }
            else
            {
                start++;
            }
            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> height = {1,8,6,2,5,4,8,3,7};
        int res = 49;
        assert(sol.maxArea(height) == res);
    }
    {
        std::vector<int> height = {1,1};
        int res = 1;
        assert(sol.maxArea(height) == res);
    }
    return 0;
}