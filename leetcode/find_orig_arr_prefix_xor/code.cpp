#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> findArray(std::vector<int>& pref) {
        std::ios::sync_with_stdio(0);
        int n = pref.size();
        for(int i = n - 1; i >= 1; i--)
        {
            pref[i] ^= pref[i - 1];
        }
        return pref;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> pref = {5,2,0,3,1};
        std::vector<int> res = {5,7,2,3,2};
        assert(sol.findArray(pref) == res);
    }
    return 0;
}