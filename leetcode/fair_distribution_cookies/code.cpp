#include <iostream>
#include <assert.h>

#include <vector>
#include <climits>

class Solution {
    void solve(std::vector<int> &cookies, int idx,  
                std::vector<int> &vals, int &res) {
        if(idx == cookies.size()) {
            int unfairness = INT_MIN;
            for(int i = 0; i < vals.size(); i++) {
                unfairness = std::max(unfairness, vals[i]);
            }
            res = std::min(res, unfairness);
            return;
        }
        for(int i = 0; i < vals.size(); i++) {
            vals[i] += cookies[idx];
            solve(cookies, idx+1, vals, res);
            vals[i] -= cookies[idx];
        }
    }
public:
    int distributeCookies(std::vector<int>& cookies, int k) {
        std::ios::sync_with_stdio(0);
        std::vector<int> vals(k, 0);
        int res = INT_MAX;
        solve(cookies, 0, vals, res);
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> cookies = {8,15,10,20,8};
        int k = 2, res = 31;
        assert(sol.distributeCookies(cookies, k) == res);
    }
    return 0;
}