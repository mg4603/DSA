#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> numberOfLines(std::vector<int>& widths, std::string s) {
        std::vector<int> res = std::vector<int>(2, 0);
        int len(0);
        for(char ch: s)
        {
            if(len + widths[ch - 'a'] > 100)
            {
                res[0]++;
                len = widths[ch - 'a'];
            }
            else
            {
                len += widths[ch - 'a'];
            }
        }
        if(len > 0)
        {
            res[0]++;
        }
        res[1] = len;
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> widths = {
            10,10,10,10,10,10,10,10,10,10,10,10,10,
            10,10,10,10,10,10,10,10,10,10,10,10,10
        };
        std::string s = "abcdefghijklmnopqrstuvwxyz";
        std::vector<int> res = {3, 60};
        assert(sol.numberOfLines(widths, s) == res);
    }
    {
        std::vector<int> widths = {
            4,10,10,10,10,10,10,10,10,10,10,10,10,
            10,10,10,10,10,10,10,10,10,10,10,10,10
        };
        std::string s = "bbbcccdddaaa";
        std::vector<int> res = {2, 4};
        assert(sol.numberOfLines(widths, s) == res);
    }
    return 0;
}