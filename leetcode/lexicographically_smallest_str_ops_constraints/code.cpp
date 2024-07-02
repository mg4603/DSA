#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string getSmallestString(std::string s, int k) {
        for(int i = 0; i < s.length(); i++) {
            int temp = s[i] - 'a';
            int diff = std::min(temp, 26 - temp);
            if(diff > k) {
                s[i] = temp - k + 'a';
                k = 0;
            }else {
                k -= diff;
                s[i] = 'a';
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "zbbz";
        int k = 3;
        std::string res = "aaaz";
        assert(sol.getSmallestString(s, k) == res);
    }
    return 0;
}