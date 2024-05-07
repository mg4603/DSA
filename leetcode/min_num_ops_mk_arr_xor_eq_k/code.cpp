#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::ios::sync_with_stdio(0);
        int sum = 0;

        for(int num: nums) {
            sum ^= num;
        }

        int res = 0;
        while(sum && k) {
            if(sum % 2 != k % 2)res++;
            sum /= 2;
            k /= 2;
        }

        while(sum) {
            if(sum % 2)res++;
            sum /= 2;
        }

        while(k) {
            if(k % 2)res++;
            k /= 2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,1,3,4};
        int k = 1;
        int res = 2;
        assert(sol.minOperations(nums, k) == res);
    }
    return 0;
}