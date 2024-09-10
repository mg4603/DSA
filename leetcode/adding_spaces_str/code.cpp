#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string addSpaces(std::string s, 
                        std::vector<int>& spaces) {
        std::ios::sync_with_stdio(0);
        std::string res;
        int idx = 0;
        int n = spaces.size();

        for(int i = 0; i < s.length(); i++) {
            if(idx < n && i == spaces[idx]) {
                res += " ";
                idx++;
            }
            res += s[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "LeetcodeHelpsMeLearn";
        std::vector<int> spaces = {8,13,15};
        std::string res = "Leetcode Helps Me Learn";
        assert(sol.addSpaces(s, spaces) == res);
    }
    return 0;
}