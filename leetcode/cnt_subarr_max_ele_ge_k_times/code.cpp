#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        long long res = 0;
        int max_ele = *std::max_element(nums.begin(), nums.end());
        int n = nums.size();

        int cnt = 0;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == max_ele)cnt++;

            while(cnt >= k)
            {
                res += (n - i);
                if(nums[j] == max_ele)cnt--;
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
        std::vector<int> nums = {1,3,2,3,3};
        int k = 2;
        int res = 6;
        assert(sol.countSubarrays(nums, k) == res);
    }
    return 0;
}