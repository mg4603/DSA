// Maximum Sum Increasing Subsequence
//      Given an array of n positive integers. Write a program to 
//      find the sum of maximum sum subsequence of the given array 
//      such that the integers in the subsequence are sorted in 
//      increasing order.

#include <vector>
#include <iostream>
#include <climits>

int maxSumIncreasingSubseq(std::vector<int> &nums, int i, int n, int prev) {
    if(i == n)return 0;

    int exc = maxSumIncreasingSubseq(nums, i + 1, n, prev);
    int inc = 0;
    if(nums[i] > prev) {
        inc = nums[i] + maxSumIncreasingSubseq(nums, i + 1, n, nums[i]);
    }
    return std::max(inc, exc);
}

int main() {
    std::vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 
                             1, 9, 5, 13, 3, 11};
    
    int n = nums.size();
    std::cout << "The maximum sum of increasing subsequence: " 
                << maxSumIncreasingSubseq(nums, 0, n, INT_MIN)
                << std::endl;;
    
    return 0;
}