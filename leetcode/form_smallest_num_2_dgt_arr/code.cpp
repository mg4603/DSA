#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minNumber(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::vector<int> digits_n1(10, 0);
        std::vector<int> digits_n2(10, 0);

        for(int i = 0; i < nums1.size(); i++)
        {
            digits_n1[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            digits_n2[nums2[i]] = 1;
        }

        int min_n1 = -1;
        int min_n2 = -1;
        for(int i = 0; i < 10; i++)
        {
            if(digits_n1[i] && digits_n2[i])
            {
                return i;
            }
            if(min_n1 == -1 && digits_n1[i])
            {
                min_n1 = i;
            }
            if(min_n2 == -1 && digits_n2[i])
            {
                min_n2 = i;
            }
        }
        if(min_n1 < min_n2)
        {
            return 10 * min_n1 + min_n2;
        }
        else
        {
            return 10 * min_n2 + min_n1;
        }

    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {4,1,3};
        std::vector<int> nums2 = {5,7};
        int res = 15;
        assert(sol.minNumber(nums1, nums2) == res);
    }
    {
        std::vector<int> nums1 = {3,5,2,6};
        std::vector<int> nums2 = {3,1,7};
        int res = 3;
        assert(sol.minNumber(nums1, nums2) == res);
    }
    return 0;
}