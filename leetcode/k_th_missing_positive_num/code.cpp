#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int findKthPositive(std::vector<int>& arr, int k) {
        int i = 0;
        int count = 0;
        int num = 1;
        while(i < arr.size() && count != k)
        {
            if(num < arr[i])
            {
                num++;
                count++;
            }
            else
            {
                num++;
                i++;
            }
        }
        while(count != k)
        {
            num++;
            count++;
        }
        return num - 1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,3,4,7,11};
        int k = 5;
        int res = 9;
        assert(sol.findKthPositive(arr, k) == res);
    }
    {
        std::vector<int> arr = {1,2,3,4};
        int k = 2;
        int res = 6;
        assert(sol.findKthPositive(arr, k) == res);
    }
    return 0;
}