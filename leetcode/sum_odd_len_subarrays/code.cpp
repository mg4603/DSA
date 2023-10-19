#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int sumOddLengthSubarrays(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        
        int n = arr.size();
        int res = 0;

        for(int i = 0; i < n; i ++)
        {
            int occurrences = ((i + 1)/ 2) * ((n-i) / 2);
            occurrences += ((i / 2) + 1) * ((n - i - 1) / 2 + 1);
            res += (occurrences * arr[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {10,11,12};
        int res = 66;
        assert(sol.sumOddLengthSubarrays(arr) == res);
    }
    {
        std::vector<int> arr = {1,2};
        int res = 3;
        assert(sol.sumOddLengthSubarrays(arr) == res);
    }
    {
        std::vector<int> arr = {1,4,2,5,3};
        int res = 58;
        assert(sol.sumOddLengthSubarrays(arr) == res);
    }
    return 0;
}