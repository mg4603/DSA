#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
public:
    int minimumIndex(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        std::unordered_map<int, int> freq;
        int dom = INT_MIN;
        int max_freq = 0;
        for(int &num: nums) {
            if(max_freq < ++freq[num]) {
                max_freq = freq[num];
                dom = num;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == dom) {
                cnt++;
                if(cnt * 2 > i + 1 && 
                    (max_freq - cnt) * 2 > (n - i - 1)) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,2,2};
        int res = 2;
        assert(sol.minimumIndex(nums) == res);
    }
    return 0;
}