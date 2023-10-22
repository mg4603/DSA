#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    double trimMean(std::vector<int>& arr) {
        int n = arr.size();
        int exclude = n / 10;
        std::sort(arr.begin(), arr.end());
        
        double res = std::accumulate(
                        arr.begin() + (exclude / 2), 
                        arr.end() - (exclude / 2), 0);
        return res / (n - exclude);
    }
};


int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,2,2,2,2,2,2,2,2,
                                2,2,2,2,2,2,2,2,2,3};
        double res = 2.00000;
        assert(sol.trimMean(arr) == res);
    }
    {
        std::vector<int> arr = {6,2,7,5,1,2,0,3,10,2,
                                5,0,5,5,0,8,7,6,8,0};
        double res = 4.00000;
        assert(sol.trimMean(arr) == res);
    }
    {
        std::vector<int> arr = {6,0,7,0,7,5,7,8,3,4,0,
                                7,8,1,6,8,1,1,2,4,8,1,
                                9,5,4,3,8,5,10,8,6,6,
                                1,0,6,10,8,2,3,4};
        double res = 4.77778;
        assert(std::abs(sol.trimMean(arr) - res) <= 10e-5);
    }
    return 0;
}