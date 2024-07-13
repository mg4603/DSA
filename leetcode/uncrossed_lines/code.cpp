#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    // lcs in numerical form
public:
    int maxUncrossedLines(std::vector<int>& nums1, 
                        std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        std::vector<std::vector<int>> table(n + 1, 
                            std::vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    table[i][j] = table[i - 1][j - 1] + 1;
                }else {
                    table[i][j] = std::max(table[i - 1][j], 
                                    table[i][j - 1]);
                }
            }
        }
        return table[n][m];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,4,2};
        std::vector<int> nums2 = {1,2,4};
        int res = 2;
        assert(sol.maxUncrossedLines(nums1, nums2) == res);
    }
    return 0;
}