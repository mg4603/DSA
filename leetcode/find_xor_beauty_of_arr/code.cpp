#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    // when i != j there will always be a pair (i, j)
    //      such that
    // ((i | j) & k) ^ ((j | i) & k) == 0

    // only need to consider cases where i == j
    
    // (i | i) == i     ==>     ((i | i) & k) == i & k

    // for every i != k there exists 
    //      (i & k) == (k & i) such that 
    //      (i & k) ^ (k & i) == 0

    // Therefore only cases to consider are ((k | k) & k) = k
    // => res is the xor of all elements in array
public:
    int xorBeauty(std::vector<int>& nums) {
        int res = 0;
        for(int &num: nums) {
            res ^= num;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,4};
        int res = 5;
        assert(sol.xorBeauty(nums) == res);
    }
    return 0;
}