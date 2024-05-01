#include <iostream>
#include <assert.h>

class Solution {
public:
    int minPartitions(std::string n) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        for(char c: n)
        {
            res = std::max(res, c - '0');
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string n = "32";
        int res = 3;
        assert(sol.minPartitions(n) == res);
    }
    return 0;
}