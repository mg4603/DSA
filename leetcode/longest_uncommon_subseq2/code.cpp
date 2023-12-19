#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool check(std::string s1, std::string s2)
    {
        int i = 0;
        int j = 0;
        int s1_len = s1.length();
        int s2_len = s2.length();
        while(i < s1_len && j < s2_len)
        {
            if(s1[i] == s2[j])
            {
                i++;
            }
            j++;
        }
        return i == s1_len;
    }

public:
    int findLUSlength(std::vector<std::string>& strs) 
    {
        int res = -1;
        int n = strs.size();

        for(int i = 0; i < n; i++)
        {
            int flag = 1;
            for(int j = 0; j < n; j++)
            {
                if(i != j && check(strs[i], strs[j]))
                {
                    flag = 0;
                    break;
                }
            }
            int curr_len = strs[i].length();
            if(flag && res < curr_len)
            {
                res = curr_len;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> strs = {"aba","cdc","eae"};
        int res = 3;
        assert(sol.findLUSlength(strs) == res);
    }
    {
        std::vector<std::string> strs = {"aaa","aaa","aa"};
        int res = -1;
        assert(sol.findLUSlength(strs) == res);
    }
    return 0;
}