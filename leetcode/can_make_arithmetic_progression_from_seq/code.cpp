#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int diff(arr[1] - arr[0]);
        for(int i(2); i < arr.size(); i++)
        {
            if(arr[i] - arr[i - 1] != diff)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {3, 5, 1};
        assert(sol.canMakeArithmeticProgression(arr) == true);
    }
    {
        std::vector<int> arr = {1,2,4};
        assert(sol.canMakeArithmeticProgression(arr) == false);
    }
    return 0;
}