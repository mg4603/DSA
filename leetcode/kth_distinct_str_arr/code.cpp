#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) 
    {
        std::unordered_map<std::string, int> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for(int i = 0; i < arr.size(); i++)
        {
            if(mp[arr[i]] == 1)
            {
                k--;
            }
            if(k == 0)
            {
                return arr[i];
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> arr = {"d","b","c","b","c","a"};
        int k = 2;
        std::string res = "a";
        assert(sol.kthDistinct(arr, k) == res);
    }
    {
        std::vector<std::string> arr = {"aaa","aa","a"};
        int k = 1;
        std::string res = "aaa";
        assert(sol.kthDistinct(arr, k) == res);
    }
    {
        std::vector<std::string> arr = {"a","b","a"};
        int k = 3;
        std::string res = "";
        assert(sol.kthDistinct(arr, k) == res);
    }
    return 0;
}