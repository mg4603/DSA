#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        std::ios_base::sync_with_stdio(0);
        if(target.size() != arr.size())
        {
            return false;
        }
        std::unordered_map<int, int> mp;
        for(int i = 0; i < target.size() ;i++)
        {
            mp[target[i]]++;
        }
        for(int i = 0; i < arr.size(); i++)
        {
            int temp = --mp[arr[i]];
            if(temp < 0)
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
        std::vector<int> target = {1,2,3,4};
        std::vector<int> arr = {2,4,1,3};
        bool res = true;
        assert(sol.canBeEqual(target, arr) == res);
    }
    {
        std::vector<int> target = {7};
        std::vector<int> arr = {7};
        bool res = true;
        assert(sol.canBeEqual(target, arr) == res);
    }
    {
        std::vector<int> target = {3,7,9};
        std::vector<int> arr = {3,7,11};
        bool res = false;
        assert(sol.canBeEqual(target, arr) == res);
    }
    return 0;
}