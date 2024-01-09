#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        int l = 0;
        int r = n - 1;

        
        while(r - l >= k)
        {
            if(std::abs(arr[l] - x) <= std::abs(arr[r] - x))
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return std::vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,3,4,5};
        int k = 4;
        int x = 3;
        std::vector<int> res = {1,2,3,4};
        assert(sol.findClosestElements(arr, k, x) == res);
    }
    return 0;
}