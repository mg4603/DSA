#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) 
    {
        
        int temp = *std::max_element(arr.begin() + 1, arr.end());
        for(int i = 0; i < arr.size() - 1; i++)
        {
            if(arr[i] == temp)
            {
                temp = *std::max_element(arr.begin() + i + 1, arr.end());
            }
            arr[i] = temp;
        }
        arr.back() = -1;
        return arr;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {17,18,5,4,6,1};
        std::vector<int> res = {18,6,6,6,1,-1};
        assert(sol.replaceElements(arr) == res);
    }
    {
        std::vector<int> arr = {400};
        std::vector<int> res = {-1};
        assert(sol.replaceElements(arr) == res);
    }
    return 0;
}