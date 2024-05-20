#include <iostream>
#include <assert.h>

class Solution {
public:
    int minFlips(std::string target) {
        std::ios::sync_with_stdio(0);
        int res = target[0] == '1';
        for(int i = 1; i < target.length(); i++) {
            if(target[i] != target[i - 1])res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string target = "10111";
        int res = 3;
        assert(sol.minFlips(target) == res);
    }
    return 0;
}