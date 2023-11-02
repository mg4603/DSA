#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
public:
    std::string convert(std::string s, int numRows) 
    {
        if(numRows == 1)
        {
            return s;
        }
        std::vector<std::string> temp(numRows);

        int row = 0;
        int diff = -1;
        for(int i = 0; i < s.length(); i++)
        {
            temp[row] += s[i];
            row += std::pow(diff, i / (numRows - 1));
        }

        std::string res;
        for(int i = 0; i < numRows; i++)
        {
            res += temp[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 3;
        std::string res = "PAHNAPLSIIGYIR";
        assert(sol.convert(s, numRows) == res);
    }
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 4;
        std::string res = "PINALSIGYAHRPI";
        assert(sol.convert(s, numRows) == res);
    }
    {
        std::string s = "A";
        int numRows = 1;
        std::string res = "A";
        assert(sol.convert(s, numRows) == res);
    }
    return 0;
}