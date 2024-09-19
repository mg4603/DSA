#include <vector>
#include <iostream>
#include <climits>

int lis(std::vector<int> nums, int i, int n, int prev) {
    if(i == n)return 0;

    int exc = lis(nums, i + 1, n, prev);

    int inc = 0;
    if(nums[i] > prev) {
        inc = lis(nums, i + 1, n, nums[i]) + 1;
    }
    return std::max(inc, exc);
}
int main() {

    std::vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 
                             1, 9, 5, 13, 3, 11, 7, 15};
    int n = nums.size();

    std::cout << "Length of longest increasing subsequence: " 
            << lis(nums, 0, n, INT_MIN) << std::endl;;
    return 0;
}