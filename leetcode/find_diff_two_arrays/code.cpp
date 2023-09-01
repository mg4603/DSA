#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i(0);
        int j(0);
        std::vector<int> answer1;
        std::vector<int> answer2;

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        nums1.erase(std::unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(std::unique(nums2.begin(), nums2.end()),nums2.end());
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                answer1.push_back(nums1[i++]);
            }
            else if(nums1[i] > nums2[j])
            {
                answer2.push_back(nums2[j++]);
            }
            else
            {
                i++;
                j++;
            }
        }
        while(i < nums1.size())
        {
            answer1.push_back(nums1[i++]);
        }
        while(j < nums2.size())
        {
            answer2.push_back(nums2[j++]);
        }
        std::vector<std::vector<int>> res;
        res.push_back(answer1);
        res.push_back(answer2);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,2,3};
        std::vector<int> nums2 = {2,4,6};
        std::vector<std::vector<int>> ans = {{1,3}, {4,6}};
        assert(sol.findDifference(nums1, nums2) == ans);
    }
    {
        std::vector<int> nums1 = {1,2,3,3};
        std::vector<int> nums2 = {1,1,2,2};
        std::vector<std::vector<int>> ans = {{3}, {}};
        assert(sol.findDifference(nums1, nums2) == ans);
    }
    return 0;
}