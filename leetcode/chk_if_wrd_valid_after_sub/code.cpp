#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isValid(std::string s) {
        std::ios::sync_with_stdio(0);
        std::string temp = "";
        for(int i = 0; i < s.length(); i++) {
            if(temp != "" && s[i] == 'c' && temp.back() == 'b') {
                temp.pop_back();
                if(temp != "" && temp.back() == 'a') {
                    temp.pop_back();
                }else {
                    return false;
                }
            }else {
                temp += s[i];
            }
        }
        return temp == "";
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aabcbc";
        bool res = true;
        assert(sol.isValid(s) == res);
    }
    return 0;
}