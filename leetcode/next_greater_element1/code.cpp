#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, 
                                std::vector<int>& nums2) {
        
        for(int i(0); i < nums1.size(); i++)
        {
            std::vector<int>::iterator it = std::find(nums2.begin(), 
                                                nums2.end(), nums1[i]);
            if(it == nums2.end())
            {
                nums1[i] = -1;
                continue;
            }
            int found(0);
            for(int j(it - nums2.begin()); j < nums2.size(); j++)
            {
                if(nums2[j] > nums1[i])
                {
                    nums1[i] = nums2[j];
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                nums1[i] = -1;
            }
        }

        return nums1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {4,1,2};
        std::vector<int> nums2 = {1,3,4,2};
        assert(sol.nextGreaterElement(nums1, nums2) == nums1);
    }
    {
        std::vector<int> nums1 = {2,4};
        std::vector<int> nums2 = {1,2,3,4};
        assert(sol.nextGreaterElement(nums1, nums2) == nums1);
    }
    return 0;
}