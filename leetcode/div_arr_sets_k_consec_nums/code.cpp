#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    bool isPossibleDivide(std::vector<int>& nums, int k) {
        std::ios::sync_with_stdio(0);
        int n = nums.size();
        if(n % k != 0)return false;
        if(n == 1)return true;
        std::sort(nums.begin(), nums.end());

        std::unordered_map<int, int> mp;
        for(int &num: nums) {
            mp[num]++;
        }

        for(int &num: nums) {
            int cnt = 0;
            if(mp[num] == 0)continue;
            int j = num;
            while(cnt < k && mp[j] > 0) {
                mp[j]--;
                j++;
                cnt++;
            }
            if(cnt != k)return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,3,3,4,4,5,6};
        int k = 4;
        bool res = true;
        assert(sol.isPossibleDivide(nums, k) == res);
    }
    return 0;
}