#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countCompleteSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> freq(2001, 0);
        int distinct = 0;

        for(int i = 0; i < n; i++)
        {
            if(freq[nums[i]] == 0)distinct++;
            freq[nums[i]] = 1;
        }

        freq.clear();
        freq.resize(2001, 0);
        int res = 0;

        int j = 0;
        int runningDist = 0;
        for(int i = 0; i < n; i++)
        {
            if(freq[nums[i]] == 0)runningDist++;
            freq[nums[i]]++;
            while(j <= i && runningDist == distinct)
            {
                res += (n - i);
                int temp = --freq[nums[j]];
                j++;
                if(temp == 0)runningDist--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,3,1,2,2};
        int res = 4;
        assert(sol.countCompleteSubarrays(nums) == res);
    }
    return 0;
}