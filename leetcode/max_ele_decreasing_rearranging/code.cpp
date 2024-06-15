#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging( 
                                std::vector<int>& arr) {
        std::ios::sync_with_stdio(0);
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        if(arr[0] > 1)arr[0] = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] > 1)arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,2,1,2,1};
        int res = 2;
        assert(
            sol.maximumElementAfterDecrementingAndRearranging(arr) 
            == res);
    }
    return 0;
}