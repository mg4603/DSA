#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, 
                                        std::vector<int>& heights) 
    {
        int n = names.size();
        
        std::map<int, std::string> mp;

        for(int i = 0; i < n; i++)
        {
            mp[heights[i]] = names[i];
        }

        std::vector<std::string> res(n);

        int ptr = n - 1;
        for(auto it: mp)
        {
            res[ptr--] = it.second;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> names = {"Mary","John","Emma"};
        std::vector<int> heights = {180,165,170};
        std::vector<std::string> res = {"Mary","Emma","John"};
        assert(sol.sortPeople(names, heights) == res);
    }
    {
        std::vector<std::string> names = {"Alice","Bob","Bob"};
        std::vector<int> heights = {155,185,150};
        std::vector<std::string> res = {"Bob","Alice","Bob"};
        assert(sol.sortPeople(names, heights) == res);
    }
    return 0;
}