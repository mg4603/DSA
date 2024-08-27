#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool isPrime(int num) {
        if(num == 1)return false;
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0)return false;
        }
        return true;
    }
public:
    int maximumPrimeDifference(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::vector<int> pos;
        for(int i = 0; i < nums.size(); i++) {
            if(isPrime(nums[i]))pos.push_back(i);
        }
        return pos.back() - pos[0];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,2,9,5,3};
        int res = 3;
        assert(sol.maximumPrimeDifference(nums) == res);
    }
    return 0;
}