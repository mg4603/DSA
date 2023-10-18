#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        int n = s.length();
        std::string res(n, ' ');
        for(int i = 0; i < n; i++)
        {
            res[indices[i]] = s[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "codeleet";
        std::vector<int> indices = {4,5,6,7,0,2,1,3};
        std::string res = "leetcode";
        assert(sol.restoreString(s, indices) == res);
    }
    {
        std::string s = "abc";
        std::vector<int> indices = {0,1,2};
        std::string res = "abc";
        assert(sol.restoreString(s, indices) == res);
    }
    return 0;
}