#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<bool> canMakePaliQueries(std::string s, 
                    std::vector<std::vector<int>>& queries) {
        std::ios::sync_with_stdio(0);
        std::vector<long long> state(1);        
        long long mask = 0LL;
        for(char ch: s)
        {
            mask ^= (1 << (ch - 'a'));
            state.push_back(mask);
        }

        std::vector<bool> res;
        for(auto & q: queries)
        {
            int l = q[0];
            int r = q[1] + 1;
            int k = q[2];

            int ones = __builtin_popcount(state[r] ^ state[l]);
            res.push_back(ones / 2 <= k);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abcda";
        std::vector<std::vector<int>> queries = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
        std::vector<bool> res = {true,false,false,true,true};
        assert(sol.canMakePaliQueries(s, queries) == res);
    }
    return 0;
}