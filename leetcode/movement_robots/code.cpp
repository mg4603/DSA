#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int sumDistance(std::vector<int>& nums, 
                    std::string s, int d) {
        std::ios::sync_with_stdio(0);
        long long mod = 1e9+7;
        int n = nums.size();

        std::vector<long long> res_pos(n, 0LL);

        for(int i = 0; i < n; i++)
        {
            res_pos[i] += nums[i];
            if(s[i] == 'L')
            {
                res_pos[i] -= d;
            }
            else
            {
                res_pos[i] += d;
            }
        }

        std::sort(res_pos.begin(), res_pos.end());
        long long preSum = 0LL;
        long long res = 0LL;

        for(long long i = 0; i < n; i++)
        {
            res += i * res_pos[i] - preSum;
            preSum += res_pos[i];
            preSum %= mod;
            res %= mod;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {-2,0,2};
        std::string s = "RLL";
        int d = 3;
        int res = 8;
        assert(sol.sumDistance(nums, s, d) == res);
    }
    return 0;
}