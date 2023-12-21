#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int dfs(std::vector<int> &nums, int i, int start, 
            std::vector<bool> &visited)
    {
        if(nums[i] == start)
        {
            return 1;
        }
        visited[i] = 1;
        return 1 + dfs(nums, nums[i], start, visited);
    }
public:
    int arrayNesting(std::vector<int>& nums) 
    {
        int n = nums.size();
        int res = 0;
        std::vector<bool> visited(n, 0);

        for(int i = 0; i < n; i++)
        {
            if(visited[i])continue;
            int temp = dfs(nums, i, i, visited);
            if(temp > res)
            {
                res = temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {5,4,0,3,1,6,2};
        int res = 4;
        assert(sol.arrayNesting(nums) == res);
    }
    {
        std::vector<int> nums = {0,1,2};
        int res = 1;
        assert(sol.arrayNesting(nums) == res);
    }
    return 0;
}