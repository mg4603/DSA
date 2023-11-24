#include <iostream>
#include <assert.h>

#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) 
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        int i = 0;
        while(k-- > 0)
        {
            q.push(nums[i]);
            i++;
        } 

        while(i < nums.size())
        {
            int temp = q.top();
            if(temp < nums[i])
            {
                q.pop();
                q.push(nums[i]);
            }
            i++;
        }
        return q.top();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {3,2,1,5,6,4};
        int k = 2;
        int res = 5;
        assert(sol.findKthLargest(nums, k) == res);
    }
    {
        std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
        int k = 4;
        int res = 4;
        assert(sol.findKthLargest(nums, k) == res);
    }
    return 0;
}