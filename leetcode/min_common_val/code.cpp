#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums2[j] < nums1[i])
            {
                j++;
            }
            else
            {
                return nums1[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,2,3};
        std::vector<int> nums2 = {2,4};
        int res = 2;
        assert(sol.getCommon(nums1, nums2) == res);
    }
    {
        std::vector<int> nums1 = {1,2,3,6};
        std::vector<int> nums2 = {2,3,4,5};
        int res = 2;
        assert(sol.getCommon(nums1, nums2) == res);
    }
    return 0;
}