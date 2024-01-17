#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findLength(std::vector<int>& nums1, 
                    std::vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        int res = 0;
        std::vector<std::vector<int>> table(n + 1, 
                            std::vector<int>(m + 1, 0));

        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(nums1[i - 1] == nums2[j - 1])
                {
                    table[i][j] = table[i - 1][j - 1] + 1;
                    res = std::max(res, table[i][j]);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,2,3,2,1};
        std::vector<int> nums2 = {3,2,1,4,7};
        int res = 3;
        assert(sol.findLength(nums1, nums2) == res);
    }
    return 0;
}