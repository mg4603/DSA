#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int i(0);
        int j(0);

        int res(0);

        while(i < g.size() && j < s.size())
        {
            if(s[j] >= g[i])
            {
                j++;
                i++;
                res++;
            }
            else
            {
                j++;
            }

        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> g = {1,2,3};
        std::vector<int> s = {1, 1};
        assert(sol.findContentChildren(g, s) == 1);
    }
    {
        std::vector<int> g = {1,2};
        std::vector<int> s = {1, 2, 3};
        assert(sol.findContentChildren(g, s) == 2);
    }
   
    return 0;
}