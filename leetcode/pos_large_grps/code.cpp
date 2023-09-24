#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> largeGroupPositions(std::string s) 
    {
        std::vector<std::vector<int>> res;
        if(s == "")
        {
            return res;
        }
        int start(0);
        char current = s[0];
        int len(0);

        for(int i(0); i < s.length(); i++)
        {
            if(s[i] != current)
            {
                if(len >= 3)
                {
                    res.push_back(std::vector<int>{start, i - 1});               
                }
                len = 0;
                start = i;
                current = s[i];
            }
            len++;
        }
        if(len >= 3)
        {
            res.push_back(std::vector<int>{start, 
                            static_cast<int>(s.length()) - 1});
        }
        return res;
    }
};


int main()
{
    Solution sol;
    {
        std::string s = "abbxxxxzzy";
        std::vector<std::vector<int>> res = {
            {3,6}
        };
        assert(sol.largeGroupPositions(s) == res);
    }
    {
        std::string s = "abc";
        std::vector<std::vector<int>> res = {};
        assert(sol.largeGroupPositions(s) == res);
    }
    {
        std::string s = "abcdddeeeeaabbbcd";
        std::vector<std::vector<int>> res = {
            {3,5}, {6,9}, {12,14}
        };
        assert(sol.largeGroupPositions(s) == res);
    }
    return 0;
}