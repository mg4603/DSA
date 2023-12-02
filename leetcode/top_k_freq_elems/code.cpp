#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
    {
        int n = nums.size();
        std::unordered_map<int, int> mp;
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> q;

        for(int i = 0; i < n; i++)
        {
            if(mp.count(nums[i]) == 0)
            {
                mp[nums[i]] = 0;
            }
            mp[nums[i]]++;
        }

        for(auto it: mp)
        {
            if(q.size() < k)
            {
                q.push(std::make_pair(it.second, it.first));
            }
            else
            {
                std::pair<int, int> top = q.top();
                if(top.first < it.second)
                {
                    q.pop();
                    q.push(std::make_pair(it.second, it.first));
                }
            }
        }
        std::vector<int> res;
        while(!q.empty())
        {
            std::pair<int, int> top = q.top();
            q.pop();
            res.push_back(top.second);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,1,1,2,2,3};
        int k = 2;
        std::vector<int> res = {2,1};
        assert(sol.topKFrequent(nums, k) == res);
    }
    {
        std::vector<int> nums = {1};
        int k = 1;
        std::vector<int> res = {1};
        assert(sol.topKFrequent(nums, k) == res);
    }
    return 0;
}