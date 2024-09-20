#include <iostream>
#include <vector>

int longestBitonicSubsequence(std::vector<int> &nums) {
    
    int n = nums.size();
    std::vector<int> longestIncreasing(n, 0);
    std::vector<int> longestDecreasing(n, 0);

    int res = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && 
                longestIncreasing[i] < longestIncreasing[j]) {
                longestIncreasing[i] = longestIncreasing[j];
            }
            longestIncreasing[i]++;
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(nums[i] > nums[j] && longestDecreasing[i] < longestDecreasing[j]) {
                longestDecreasing[i] = longestDecreasing[j];
            }
            longestDecreasing[i]++;
        }
    }

    for(int i = 0; i < n; i++) {
        res = std::max(longestDecreasing[i] + longestIncreasing[i] - 1, res);
    }
    return res;
}

int main() {
    std::vector<int> nums = {4, 2, 5, 9, 7, 6, 10, 3, 1};
    std::cout << "Length of longest Bitonic Sequence: " 
            << longestBitonicSubsequence(nums) << std::endl;
    return 0;
}