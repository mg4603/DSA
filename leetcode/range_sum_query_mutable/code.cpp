#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class NumArray {
    std::vector<int> tree;
    int n;

    void constructTree(std::vector<int> &nums, 
                       int low, int high, int pos)
    {
        if(low >= n || high >= n || low < 0 || high < 0)
        {
            return;
        }
        if(low == high)
        {
            tree[pos] = nums[low];
            return;
        }
        int mid = (low + high) / 2;

        constructTree(nums, low, mid, 2 * pos + 1);
        constructTree(nums, mid + 1, high, 2 * pos + 2);
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    void updateTree(int index, int val, 
                    int low, int high, int pos)
    {
        
        if(low < 0 || high < 0 || 
           low >= n || high >= n)
        {
            return;
        }

        if(low == high)
        {
            tree[pos] = val;
            return;
        }
        
        int mid = (low + high) / 2;
        if(mid < index)
        {
            updateTree(index, val, mid + 1, high, 2 * pos + 2);
        }
        else
        {
            updateTree(index, val, low, mid, 2 * pos + 1);
        }
        tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
    }

    int getSum(int left, int right, 
               int low, int high, int pos)
    {
        if(low < 0 || high < 0 || low >= n || high >= n)
        {
            return 0;
        }
        if(left  <= low && right >= high)
        {
            return tree[pos];
        }

        if(left > high || right < low)
        {
            return 0;
        }

        int mid = (low + high) / 2;
        int leftSum = getSum(left, right, low, 
                             mid, 2 * pos + 1);
        int rightSum = getSum(left, right, mid + 1, 
                              high, 2 * pos + 2);

        return leftSum + rightSum;
    }
public:
    NumArray(std::vector<int>& nums) 
    {
        n = nums.size();
        tree.resize(std::pow(2, std::ceil(std::log2(n)) + 1) - 1);
        constructTree(nums, 0, n - 1, 0);
    }
    
    void update(int index, int val) 
    {
        updateTree(index, val, 0, n - 1, 0);
    }
    
    int sumRange(int left, int right) 
    {
        return getSum(left, right, 0, n - 1, 0);
    }
};

int main()
{
    std::vector<int> nums = {1, 3, 5};
    NumArray obj(nums);
    assert(obj.sumRange(0, 2) == 9);
    obj.update(1, 2);
    assert(obj.sumRange(0, 2) == 8);
    return 0;
}