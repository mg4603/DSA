#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int findSpecialInteger(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        if(arr.size() == 1)
        {
            return arr[0];
        }
        
        std::unordered_map<int, int> freq;
        for(int i = 0; i < arr.size(); i++)
        {
            int temp = ++freq[arr[i]];
            if(temp > arr.size() / 4)
            {
                return arr[i];
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,2,6,6,6,6,7,10};
        int res = 6;
        assert(sol.findSpecialInteger(arr) == res);
    }
    {
        std::vector<int> arr = {1,1};
        int res = 1;
        assert(sol.findSpecialInteger(arr) == res);
    }
    return 0;
}