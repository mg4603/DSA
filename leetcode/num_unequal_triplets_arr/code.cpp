#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int unequalTriplets(std::vector<int>& nums) {
        std::vector<int> freq(1001, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        freq.erase(std::remove(freq.begin(), freq.end(), 0), freq.end());
        if(freq.size() < 3)
        {
            return 0;
        }
        
        int n = freq.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n ;j ++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    res += freq[i] * freq[j] * freq[k];
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
        std::vector<int> nums = {4,4,2,4,3};
        int res = 3;
        assert(sol.unequalTriplets(nums) == res);
    }
    {
        std::vector<int> nums = {1,1,1,1,1};
        int res = 0;
        assert(sol.unequalTriplets(nums) == res);
    }
    return 0;
}