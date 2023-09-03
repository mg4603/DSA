#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        for(int i(0); i < flowerbed.size(); i++)
        {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,0,0,0,1};
        assert(sol.canPlaceFlowers(nums, 1) == true);
    }
     {
        std::vector<int> nums = {1,0,0,0,1};
        assert(sol.canPlaceFlowers(nums, 2) == false);
    }
    return 0;
}