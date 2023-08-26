#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i(m - 1);
        int j(n - 1);
        int k(m + n - 1);
        while(j >= 0)
        {
            if(i >= 0 && nums1[i] > nums2[j])
            {
                
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,2,3,0,0,0};
        int m = 3;
        std::vector<int> nums2 = {2,5,6};
        int n = 3;
        std::vector<int> res = {1,2,2,3,5,6};
        sol.merge(nums1, m, nums2, n);
        assert(nums1 == res);
    }
    {
        std::vector<int> nums1 = {1};
        int m = 1;
        std::vector<int> nums2 = {};
        int n = 0;
        std::vector<int> res = {1};
        sol.merge(nums1, m, nums2, n);
        assert(nums1 == res);
    }
    {
        std::vector<int> nums1 = {0};
        int m = 0;
        std::vector<int> nums2 = {1};
        int n = 1;
        std::vector<int> res = {1};
        sol.merge(nums1, m, nums2, n);
        assert(nums1 == res);
    }
    return 0;
}