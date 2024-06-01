#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::ios::sync_with_stdio(0);
        int left = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')left++;
            else if(s[i] == ')')left--;

            if(left < 0) {
                s.erase(i, 1);
                left++;
                i--;
            }
        }
        if(left == 0)return s;

        int i = n - 1;
        while(i >= 0 && left > 0) {
            if(s[i] == '(') {
                s.erase(i, 1);
                left--;
            }
            i--;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "lee(t(c)o)de)";
        std::string res = "lee(t(c)o)de";
        assert(sol.minRemoveToMakeValid(s) == res);
    }
    return 0;
}