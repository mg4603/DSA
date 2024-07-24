#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        std::unordered_map<int, int> freq;
        for(int &num: nums) {
            freq[num]++;
        }

        for(auto &it: freq) {
            int temp = it.second;
            if(temp < 2)return -1;
            else if(temp % 3 == 0) {
                res += temp / 3;
            }else {
                res += temp / 3;
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,3,3,2,2,4,2,3,4};
        int res = 4;
        assert(sol.minOperations(nums) == res);
    }
    return 0;
}