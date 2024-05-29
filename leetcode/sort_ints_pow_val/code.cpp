#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    int compute(int n) {
        if(n == 1)return 0;
        if(n % 2) {
            return 1 + compute(3 * n + 1);
        } 
        return 1 + compute(n / 2);
    }
public:
    int getKth(int lo, int hi, int k) {
        std::ios::sync_with_stdio(0);
        
        std::vector<std::pair<int, int>> arr;
        for(int i = lo; i <= hi; i++) {
            arr.push_back({compute(i), i});
        }
        std::sort(arr.begin(), arr.end());
        return arr[k - 1].second;
    }
};

int main()
{
    Solution sol;
    {
        int lo = 12, hi = 15, k = 2;
        int res = 13;
        assert(sol.getKth(lo, hi, k) == res);
    }
    return 0;
}