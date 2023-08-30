#include <iostream>
#include <assert.h>

#include <vector>

class NumArray {
    std::vector<int> nums;
public:
    NumArray(std::vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        int sum(0);
        for(int i(left); i <= right; i++)
        {
            sum += nums[i];
        }
        return sum;
    }
};


int main()
{
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);

    assert(obj.sumRange(0, 2) == 1);
    assert(obj.sumRange(2, 5) == -1);
    assert(obj.sumRange(0, 5) == -3);

    return 0;
}