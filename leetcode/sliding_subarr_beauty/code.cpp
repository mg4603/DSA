#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> getSubarrayBeauty(std::vector<int>& nums, 
                                        int k, int x) {
        std::vector<int> freq(51, 0);
        int n = nums.size();
        std::vector<int> res(n - k + 1, 0);

        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < 0)freq[-nums[i]]++;
            if(i - j + 1 == k)
            {
                int cnt = 0;
                for(int p = 50; p >= 0; p--)
                {
                    cnt+= freq[p];
                    if(cnt >= x)
                    {
                        res[i - k + 1] = -p;
                        break;
                    }
                }
                if(nums[j] < 0)freq[-nums[j]]--;
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
        std::vector<int> nums = {1,-1,-3,-2,3};
        int k = 3;
        int x = 2;
        std::vector<int> res = {-1,-2,-2};
        assert(sol.getSubarrayBeauty(nums, k , x) == res);
    }
    return 0;
}