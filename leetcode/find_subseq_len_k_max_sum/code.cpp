#include <iostream>
#include <assert.h>

#include <queue>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k) 
    {
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> q;
        for(int i = 0; i < nums.size(); i++)
        {
            q.push(std::make_pair(nums[i], i));
            if(q.size() > k)
            {
                q.pop();
            }
        }

        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> q2;
        while(!q.empty())
        {
            std::pair<int, int> temp = q.top();
            q.pop();
            q2.push(std::make_pair(temp.second, temp.first));
        }

        std::vector<int> res;
        while(!q2.empty())
        {
            res.push_back(q2.top().second);
            q2.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,1,3,3};
        int k = 2;
        std::vector<int> res = {3,3};
        assert(sol.maxSubsequence(nums, k) == res);
    }
    {
        std::vector<int> nums = {-1,-2,3,4};
        int k = 3;
        std::vector<int> res = {-1,3,4};
        assert(sol.maxSubsequence(nums, k) == res);
    }
    {
        std::vector<int> nums = {3,4,3,3};
        int k = 2;
        std::vector<int> res = {4,3};
        assert(sol.maxSubsequence(nums, k) == res);
    }
    return 0;
}