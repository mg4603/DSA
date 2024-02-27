#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        int res = std::numeric_limits<int>::max();
        int minLen = std::numeric_limits<int>::max();;
        int runningSum = 0;
        std::vector<int> best(n, res);
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            runningSum += arr[i];

            while(runningSum > target)
            {
                runningSum -= arr[j];
                j++;
            }

            if(runningSum == target)
            {
                if(j > 0 && best[j - 1] != 
                        std::numeric_limits<int>::max())
                {
                    res = std::min(res, best[j - 1] + 
                                        i - j + 1);
                }
                minLen = std::min(minLen, i - j + 1);
            }
            best[i] = minLen;
        }
        return res == std::numeric_limits<int>::max() ? -1 : res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {7,3,4,7};
        int target = 7;
        int res = 2;
        assert(sol.minSumOfLengths(arr, target) == res);
    }
    return 0;
}