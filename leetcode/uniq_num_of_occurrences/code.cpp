#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> freq_mp;
        for(int i = 0; i < arr.size(); i++)
        {
            freq_mp[arr[i]]++;
        }
        std::unordered_set<int> freq_st;
        for(auto pair: freq_mp)
        {
            freq_st.insert(pair.second);
        }
        return freq_st.size() == freq_mp.size();

    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> arr = {1,2,2,1,1,3};
        bool res = true;
        assert(sol.uniqueOccurrences(arr) == res);
    }
    {
        std::vector<int> arr = {1,2};
        bool res = false;
        assert(sol.uniqueOccurrences(arr) == res);
    }
    {
        std::vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
        bool res = true;
        assert(sol.uniqueOccurrences(arr) == res);
    }
    return 0;
}