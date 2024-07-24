#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool doesValidArrayExist(std::vector<int>& derived) {
        std::ios::sync_with_stdio(0);
        int res = 0;
        for(int i = 0; i < derived.size(); i++) {
            res ^= derived[i];
        }
        return res == 0;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> derived = {1,1,0};
        bool res = true;
        assert(sol.doesValidArrayExist(derived) == res);
    }
    return 0;
}