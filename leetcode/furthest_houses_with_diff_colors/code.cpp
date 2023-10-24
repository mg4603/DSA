#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& colors) 
    {
        std::ios_base::sync_with_stdio(0);
        int res = 0;
        int n = colors.size();
        for(int i = 0; i < n; i++)
        {
            if(colors[i] != colors[n - 1] || 
               colors[n - i - 1] != colors[0])
            {
                return (n - 1) - i;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> colors = {1,1,1,6,1,1,1};
        int res = 3;
        assert(sol.maxDistance(colors) == res);
    }
    {
        std::vector<int> colors = {1,8,3,8,3};
        int res = 4;
        assert(sol.maxDistance(colors) == res);
    }
    {
        std::vector<int> colors = {0,1};
        int res = 1;
        assert(sol.maxDistance(colors) == res);
    }
    return 0;
}