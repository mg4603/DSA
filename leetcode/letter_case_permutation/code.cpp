#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void solve(std::string &s, 
                std::vector<std::string> &res, 
                int i = 0) {
        if(i == s.length()) {
            res.push_back(s);
        }else {
            if(isdigit(s[i])) {
                solve(s, res, i + 1);
            }else {
                s[i] = tolower(s[i]);
                solve(s, res, i + 1);
                s[i] = toupper(s[i]);
                solve(s, res, i + 1);
            }
        }
    }
public:
    std::vector<std::string> letterCasePermutation(
                            std::string s) {
        std::vector<std::string> res;
        solve(s, res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "a1b2";
        std::vector<std::string> res = {"a1b2","a1B2","A1b2","A1B2"};
        assert(sol.letterCasePermutation(s) == res);
    }
    return 0;
}