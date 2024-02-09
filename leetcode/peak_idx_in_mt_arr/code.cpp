#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) 
    {
        int n = arr.size();
        int l = 0;
        int r = n - 1;

        while(l < r)
        {
            int mid = (l + r)/2;

            if(mid > 0 && arr[mid - 1] < arr[mid] && 
                mid < n - 1 && arr[mid + 1] < arr[mid])
            {
                return mid;
            }
            if(mid > 0 && arr[mid - 1] < arr[mid] && 
                mid < n - 1 && arr[mid + 1] > arr[mid])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }    
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {0,1,0};
        int res = 1;
        assert(sol.peakIndexInMountainArray(arr) == res);
    }
    return 0;
}