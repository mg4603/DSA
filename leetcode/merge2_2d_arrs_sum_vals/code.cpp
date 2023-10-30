#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> mergeArrays(
                                    std::vector<std::vector<int>>& nums1, 
                                    std::vector<std::vector<int>>& nums2) 
    {
        std::vector<std::vector<int>> res;
        int i = 0;
        int j = 0;

        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        while(i < nums1_size && j < nums2_size)
        {
            if(nums1[i][0] < nums2[j][0])
            {
                res.push_back(nums1[i++]);
            }
            else if(nums2[j][0] < nums1[i][0])
            {
                res.push_back(nums2[j++]);
            }
            else
            {
                nums1[i][1] += nums2[j++][1];
                res.push_back(nums1[i++]);
            }
        }
        while(i < nums1_size)
        {
            res.push_back(nums1[i++]);
        }

        while(j < nums2_size)
        {
            res.push_back(nums2[j++]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> nums1 = {
            {1,2},{2,3},{4,5}};
        std::vector<std::vector<int>> nums2 = {
            {1,4},{3,2},{4,1}};
        std::vector<std::vector<int>> res = {
            {1,6},{2,3},{3,2},{4,6}};
        assert(sol.mergeArrays(nums1, nums2) == res);
    }
    {
        std::vector<std::vector<int>> nums1 = {
            {2,4},{3,6},{5,5}};
        std::vector<std::vector<int>> nums2 = {
            {1,3},{4,3}};
        std::vector<std::vector<int>> res = {
            {1,3},{2,4},{3,6},{4,3},{5,5}};
        assert(sol.mergeArrays(nums1, nums2) == res);
    }
    return 0;
}