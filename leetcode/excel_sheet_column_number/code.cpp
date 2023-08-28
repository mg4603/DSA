#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int res(0);

        for(int i(0); i < columnTitle.size(); i++)
        {
            res += std::pow(26, i) * (columnTitle[columnTitle.size() - 1 - i] - 'A' + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.titleToNumber("A") == 1);
    }
    {
        assert(sol.titleToNumber("AB") == 28);
    }
    {
        assert(sol.titleToNumber("ZY") == 701);
    }
    return 0;
}