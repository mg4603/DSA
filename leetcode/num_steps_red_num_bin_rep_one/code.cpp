#include <iostream>
#include <assert.h>

class Solution {
    void increment(std::string &s) {
        int flag = 1;
        int n = s.length();
        s[n - 1] = '0';
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == '0') {
                s[i] = '1';
                flag = 0;
                break;
            }else {
                s[i] = '0';
            }
        }

        if(flag) {
            s = '1' + s;
        }
    }
public:
    int numSteps(std::string s) {
        int res = 0;
        while(s.size() != 1) {
            if(s.back() == '1') {
                increment(s);
            }else {
                s.pop_back();
            }
            res++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "1101";
        int res = 6;
        assert(sol.numSteps(s) == res);
    }
    return 0;
}