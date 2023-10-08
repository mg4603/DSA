#include <iostream>
#include <assert.h>

#include <vector>
#include <numeric>

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        int expected_sum = std::accumulate(arr.begin(), arr.end(), 0);
        if(expected_sum % 3 != 0 || arr.size() < 3)
        {
            return false;
        }

        expected_sum /= 3;
        int partition_sum = 0;
        int count = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            if(count == 2)
            {
                return true;
            }
            partition_sum += arr[i];
            if(partition_sum == expected_sum)
            {
                partition_sum = 0;
                count++;
            }
        } 
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {0,2,1,-6,6,-7,9,1,2,0,1};
        bool res = true;
        assert(sol.canThreePartsEqualSum(arr) == res);
    }
    {
        std::vector<int> arr = {0,2,1,-6,6,7,9,-1,2,0,1};
        bool res = false;
        assert(sol.canThreePartsEqualSum(arr) == res);
    }
    {
        std::vector<int> arr = {3,3,6,5,-2,2,5,1,-9,4};
        bool res = true;
        assert(sol.canThreePartsEqualSum(arr) == res);
    }
    return 0;
}