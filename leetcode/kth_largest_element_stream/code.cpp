#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class KthLargest {
    int k;
    std::vector<int> nums;
public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        std::sort(nums.begin(), nums.end());
        this->nums = nums;
    }
    
    int add(int val) {
        this->nums.push_back(val);
        int i(this->nums.size() - 2);
        while(i >= 0 && this->nums[i] >= val)
        {
            this->nums[i + 1] = this->nums[i];
            i--;
        }
        this->nums[i + 1] = val;
        
        return this->nums[this->nums.size() - k];
    }
};

int main()
{
    std::vector<int> nums = {4, 5, 8, 2};
    KthLargest obj(3, nums);
    
    assert(obj.add(3) == 4);
    assert(obj.add(5) == 5);
    assert(obj.add(10) == 5);
    assert(obj.add(9) == 8);
    assert(obj.add(4) == 8);
    return 0;
}