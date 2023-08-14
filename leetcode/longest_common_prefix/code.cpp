#include <assert.h>
#include <iostream>

#include <algorithm>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.size() == 0)
        {
            return "";
        }

        if(strs.size() == 1)
        {
            return strs[0];
        }

        std::sort(strs.begin(), strs.end());

        int n(std::min(strs[0].size(), strs.back().size()));

        std::string res;
        int i(0);
        while(i < n)
        {
            if(strs[0][i] == strs.back()[i])
            {
                res += strs[0][i];
            }
            else
            {
                break;
            }
            i++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> strs({"flower","flow","flight"});
        assert(sol.longestCommonPrefix(strs) == "fl");
    }
    {
        std::vector<std::string> strs({"dog","racecar","car"});
        assert(sol.longestCommonPrefix(strs) == "");
    }
    return 0;
}