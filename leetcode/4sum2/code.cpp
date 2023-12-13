#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, 
                     std::vector<int>& nums2, 
                     std::vector<int>& nums3, 
                     std::vector<int>& nums4) 
    {
        int n = nums1.size();
        std::unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mp[nums1[i] + nums2[j]]++;
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int temp = nums3[i] + nums4[j];
                res += mp[-temp];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,2};
        std::vector<int> nums2 = {-2,-1};
        std::vector<int> nums3 = {-1,2};
        std::vector<int> nums4 = {0,2};
        int res = 2;
        assert(sol.fourSumCount(nums1, nums2, nums3, nums4) == res);
    }
    {
        std::vector<int> nums1 = {0};
        std::vector<int> nums2 = {0};
        std::vector<int> nums3 = {0};
        std::vector<int> nums4 = {0};
        int res = 1;
        assert(sol.fourSumCount(nums1, nums2, nums3, nums4) == res);
    }
    return 0;
}