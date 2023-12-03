#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, 
                                                 std::vector<int>& nums2, 
                                                 int k) 
    {
        std::set<std::pair<int, int>> visited;
        std::vector<std::vector<int>> res;
        std::priority_queue<std::vector<int>, 
                            std::vector<std::vector<int>>, 
                            std::greater<std::vector<int>>> q;

        visited.insert({0, 0});
        q.push({nums1[0] + nums2[0], 0, 0});
        int n1 = nums1.size();
        int n2 = nums2.size();

        while(k-- && !q.empty())
        {
            std::vector<int> temp = q.top();
            q.pop();
            
            int i = temp[1];
            int j = temp[2];

            res.push_back({nums1[i], nums2[j]});

            if(i + 1 < n1 && 
                    visited.find({i + 1, j}) == 
                            visited.end())
            {
                visited.insert({i + 1, j});
                q.push({nums1[i + 1] + nums2[j], i + 1, j});
            }

            if(j + 1 < n2 && 
                    visited.find({i, j + 1}) == 
                            visited.end())
            {
                visited.insert({i, j + 1});
                q.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,7,11};
        std::vector<int> nums2 = {2,4,6};
        int k = 3;
        std::vector<std::vector<int>> res = {{1,2},{1,4},{1,6}};
        assert(sol.kSmallestPairs(nums1, nums2, k) == res);
    }
    {
        std::vector<int> nums1 = {1,1,2};
        std::vector<int> nums2 = {1,2,3};
        int k = 2;
        std::vector<std::vector<int>> res = {{1,1},{1,1}};
        assert(sol.kSmallestPairs(nums1, nums2, k) == res);
    }
    {
        std::vector<int> nums1 = {1,2};
        std::vector<int> nums2 = {3};
        int k = 3;
        std::vector<std::vector<int>> res = {{1,3},{2,3}};
        assert(sol.kSmallestPairs(nums1, nums2, k) == res);
    }
    return 0;
}