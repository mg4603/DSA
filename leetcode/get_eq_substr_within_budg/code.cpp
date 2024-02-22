#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int equalSubstring(std::string s, 
                        std::string t, 
                        int maxCost) {

        int n = s.length();
        std::vector<int> diff(n);
        for(int i = 0; i < n; i++)
        {
            diff[i] = std::abs(s[i] - t[i]);
        }

        int j = 0;
        int res = 0;
        int curr = 0;

        for(int i = 0; i < n; i++)
        {
            curr += diff[i];
            while(j <= i && curr > maxCost)
            {
                curr -= diff[j];
                j++;
            }    
            res = std::max(res, i - j + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abcd";
        std::string t = "bcdf";
        int maxCost = 3;
        int res = 3;
        assert(sol.equalSubstring(s, t, maxCost) == res);
    }
    return 0;
}