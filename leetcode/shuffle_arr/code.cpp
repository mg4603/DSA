#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    std::vector<int> original;
    std::vector<int> arr;

public:
    Solution(std::vector<int>& nums) 
    {
        original = nums;
        arr = nums;
    }
    
    std::vector<int> reset() 
    {
        arr = original;
        return arr;
    }
    
    std::vector<int> shuffle() 
    {
        arr.clear();
        std::vector<int> temp = original;
        while(temp.size())
        {
            int idx = rand() % temp.size();
            arr.push_back(temp[idx]);
            temp.erase(idx + temp.begin());
        }
        return arr;
    }
};

void shuffle_equal(std::vector<int> v1, std::vector<int> v2)
{
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    assert(v1 == v2);
}

int main()
{
    std::vector<int> list = {1, 2, 3};
    Solution sol(list);
    shuffle_equal(sol.shuffle(), list);
    
    assert(sol.reset() == list);
    shuffle_equal(sol.shuffle(), list);

 
    return 0;
}