#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int partitionString(std::string s) {
        std::ios::sync_with_stdio(0);
        int res = 1;
        int l = 0;
        std::vector<int> prev_pos(26, -1);
        for(int i = 0; i < s.length(); i++) {
            if(prev_pos[s[i] - 'a'] >= l) {
                res++;
                l = i;
            }
            prev_pos[s[i] - 'a'] = i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abacaba";
        int res = 4;
        assert(sol.partitionString(s) == res);
    }
    return 0;
}