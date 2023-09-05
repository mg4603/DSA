#include <iostream>
#include <assert.h>

#include <algorithm>

class Solution {
public:
    bool checkRecord(std::string s) {
        if(s.find("LLL") != std::string::npos)
        {
            return false;
        }

        int absent(std::count(s.begin(), s.end(), 'A'));
        return absent < 2;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.checkRecord("PPALLP") == true);
        assert(sol.checkRecord("PPALLL") == false);
    }
    return 0;
}