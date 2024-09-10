// Maximum Sum Increasing Subsequence
//      Given an array of n positive integers. Write a program to 
//      find the sum of maximum sum subsequence of the given array 
//      such that the integers in the subsequence are sorted in 
//      increasing order.

#include <vector>
#include <iostream>
#include <assert.h>

int maxSumIncreasingSubseq(std::vector<int> &nums) {
    int res = 0;
    int n = nums.size();
    std::vector<int> sums = nums;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[j] > nums[i]) {
                sums[j] += nums[i];
            }
        }

        res = std::max(res, sums[i]);
    }
    return res;
}

int main() {
    std::vector<int> nums = {1, 101, 2, 3, 100, 4, 5};
    int res = 106;
    assert(maxSumIncreasingSubseq(nums) == res);

    nums = {3, 4, 5, 10};
    res = 22;
    assert(maxSumIncreasingSubseq(nums) == res);
    
    nums = {10, 5, 4, 3};
    res = 10;
    assert(maxSumIncreasingSubseq(nums) == res);
    
    return 0;
}