#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool validMountainArray(std::vector<int>& arr) {
        if(arr.size() < 3)
        {
            return false;
        }
        int i(0);
        while(i + 1 < arr.size() && arr[i + 1] > arr[i])
        {
            i++;
        }
        if(i == 0 || i == arr.size() - 1)
        {
            return false;
        }
        i++;
        while(i < arr.size() && arr[i - 1] > arr[i])
        {
            i++;
        }
        return i == arr.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {2,1};
        bool output = false;
        assert(sol.validMountainArray(arr) == output);
    }
    {
        std::vector<int> arr = {3,5,5};
        bool output = false;
        assert(sol.validMountainArray(arr) == output);
    }
    {
        std::vector<int> arr = {0,3,2,1};
        bool output = true;
        assert(sol.validMountainArray(arr) == output);
    }
    return 0;
}