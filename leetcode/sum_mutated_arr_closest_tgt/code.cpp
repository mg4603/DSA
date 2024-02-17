#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findBestValue(std::vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0;
        std::sort(arr.begin(), arr.end());

        while(i < n && arr[i] * (n - i) < target)
        {
            target -= arr[i];
            i++;
        }
        return i == n ? arr[n-1] : 
                        round((target - 0.00001) / (n - i));
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,3,5};
        int target = 10;
        int res = 5;
        assert(sol.findBestValue(arr, target) == res);
    }
    return 0;
}