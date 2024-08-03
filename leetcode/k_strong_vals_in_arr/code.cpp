#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> getStrongest(std::vector<int>& arr, int k) {
        std::ios::sync_with_stdio(0);
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2];

        std::vector<int> res;

        int l = 0;
        int r = n - 1;
        while(l <= r && k--) {
            if(std::abs(arr[l] - m) > std::abs(arr[r] - m)) {
                res.push_back(arr[l]);
                l++;
            }else {
                res.push_back(arr[r]);
                r--;
            }
        }
        return res; 
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,3,4,5};
        int k = 2;
        std::vector<int> res = {5, 1};
        assert(sol.getStrongest(arr, k) == res);
    }
    return 0;
}