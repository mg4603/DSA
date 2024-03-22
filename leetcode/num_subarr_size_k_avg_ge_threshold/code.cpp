#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr, 
                        int k, int threshold) 
    {
        int n = arr.size();
        int res = 0;
        int runningSum = 0;

        for(int i = 0; i < k; i++)
        {
            runningSum += arr[i];
        }

        for(int i = k; i < n; i++)
        {
            if(runningSum >= threshold * k)
            {
                res++;
            }
            runningSum -= arr[i - k];
            runningSum += arr[i];
        }

        if(runningSum >= threshold * k)
        {
            res++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,2,2,2,5,5,5,8};
        int k = 3;
        int threshold = 4;
        int res = 3;
        assert(sol.numOfSubarrays(arr, k, threshold) == res);
    }
    return 0;
}