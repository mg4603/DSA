#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        std::vector<int> arr_cp(arr);
        std::sort(arr_cp.begin(), arr_cp.end());
        std::unordered_map<int, int> mp;
        arr_cp.erase(std::unique(arr_cp.begin(), arr_cp.end()), arr_cp.end());
        for(int i = 0; i < arr_cp.size(); i++)
        {
            mp[arr_cp[i]] = i + 1;
        }

        for(int i = 0; i < arr.size(); i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {40,10,20,30};
        std::vector<int> res = {4,1,2,3};
        assert(sol.arrayRankTransform(arr) == res);
    }
    {
        std::vector<int> arr = {100,100,100};
        std::vector<int> res = {1,1,1};
        assert(sol.arrayRankTransform(arr) == res);
    }
    {
        std::vector<int> arr = {37,12,28,9,100,56,80,5,12};
        std::vector<int> res = {5,3,4,2,8,6,7,1,3};
        assert(sol.arrayRankTransform(arr) == res);
    }
    return 0;
}