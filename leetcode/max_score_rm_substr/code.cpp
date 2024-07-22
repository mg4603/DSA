#include <iostream>
#include <assert.h>

class Solution {
    int helper(std::string &s, char first, char second, int val) {
        int res = 0;
        std::string temp;
        for(char &ch: s) {
            if(temp != "" && temp.back() == first && ch == second) {
                    temp.pop_back();
                    res += val;
                    continue;               
            }
            temp += ch;
        }
        s = temp;
        return res;
    }
public:
    int maximumGain(std::string s, int x, int y) {
        int res = 0;
        if(x > y) {
            res += helper(s, 'a', 'b', x);
            res += helper(s, 'b', 'a', y);
        }else {
            res += helper(s, 'b', 'a', y);
            res += helper(s, 'a', 'b', x);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "cdbcbbaaabab";
        int x = 4, y = 5, res = 19;
        assert(sol.maximumGain(s, x, y) == res);
    }
    return 0;
}