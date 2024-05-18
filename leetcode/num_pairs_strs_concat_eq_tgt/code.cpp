#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
    bool isPrefix(std::string &str, std::string &s) {
        if(str.size() > s.size())return false;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != s[i])return false;
        }
        return true;
    }
public:
    int numOfPairs(std::vector<std::string>& nums, 
                    std::string target) {
        int res = 0;
        int n = nums.size();
        std::unordered_map<std::string, int> mp;
        for(std::string &num: nums) {
            mp[num]++;
        }

        for(std::string &num: nums) {
            if(isPrefix(num, target)) {
                std::string suffix = target.substr(num.size());
                mp[num]--;
                res += mp[suffix];
                mp[num]++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> nums = {"777","7","77","77"};
        std::string target = "7777";
        int res = 4;
        assert(sol.numOfPairs(nums, target) == res);
    }
    return 0;
}