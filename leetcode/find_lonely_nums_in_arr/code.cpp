#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> findLonely(std::vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::unordered_map<int, int> freq;
        for(int &num: nums) {
            freq[num]++;
        }

        std::vector<int> res;
        for(auto &it: freq) {
            if(it.second == 1 && 
                !(freq.count(it.first - 1) 
                || freq.count(it.first + 1))){
                res.push_back(it.first);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {10, 6, 5, 8};
        std::vector<int> res = {8, 10};
        assert(sol.findLonely(nums) == res);
    }
    return 0;
}