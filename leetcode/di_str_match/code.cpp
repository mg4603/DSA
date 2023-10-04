#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        std::vector<int> res(s.size() + 1, 0);
        int start(0);
        int end(s.length());
        for(int i(0); i < s.size(); i++)
        {
            if(s[i] == 'I')
            {
                res[i] = start++;
            }
            else
            {
                res[i] = end--;
            }
        }
        res[res.size() - 1] = start;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "IDID";
        std::vector<int> res = {0,4,1,3,2};
        assert(sol.diStringMatch(s) == res);
    }
    {
        std::string s = "III";
        std::vector<int> res = {0,1,2,3};
        assert(sol.diStringMatch(s) == res);
    }
    {
        std::string s = "DDI";
        std::vector<int> res = {3,2,0,1};
        assert(sol.diStringMatch(s) == res);
    }
    return 0;
}