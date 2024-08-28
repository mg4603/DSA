#include <iostream>
#include <assert.h>

#include <vector>


class Solution {
public:
    int xorAllNums(std::vector<int>& nums1, 
                    std::vector<int>& nums2) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        if(nums1.size() % 2 == 1) {
            for(int &num: nums2) {
                res ^= num;
            }
        }

        if(nums2.size() % 2 == 1) {
            for(int &num: nums1) {
                res ^= num;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {2,1,3};
        std::vector<int> nums2 = {10,2,5,0};
        int res = 13;
        assert(sol.xorAllNums(nums1, nums2) == res);
    }
    return 0;
}