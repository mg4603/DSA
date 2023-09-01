#include <iostream>
#include <assert.h>

#include <algorithm>

class Solution {
public:
    std::string licenseKeyFormatting(std::string s, int k) {
        s.erase(std::remove(s.begin(), s.end(), '-'), s.end());
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);

        int count(0);
        for(int i(s.size() - 1); i >= 0; i--)
        {
            count++;
            if(count == k)
            {
                s.insert(i, "-");
                count = 0;
            }
        }

        if(s.size() > 0 && s[0] == '-')
        {
            s = s.substr(1);
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "5F3Z-2e-9-w";
        assert(sol.licenseKeyFormatting(s, 4) == "5F3Z-2E9W");
    }
    {
        std::string s = "2-5g-3-J";
        assert(sol.licenseKeyFormatting(s, 2) == "2-5G-3J");
    }
    return 0;
}