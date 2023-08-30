#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> res;
        
        int i(0);
        int j(0);
        
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,2,2,1};
        std::vector<int> nums2 = {2,2};
        assert(sol.intersect(nums1, nums2) == std::vector<int>({2,2}));
    }
    {
        std::vector<int> nums1 = {4,9,5};
        std::vector<int> nums2 = {9,4,9,8,4};
        assert(sol.intersect(nums1, nums2) == std::vector<int>({4,9}));
    }
    return 0;
}