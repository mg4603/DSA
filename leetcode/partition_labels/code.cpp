#include <iostream>
#include <assert.h>

#include <vector>
#include <array>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::ios::sync_with_stdio(0);
        std::vector<std::array<int, 2>> pos(26, {-1, -1});
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(pos[s[i] - 'a'][0] == -1)pos[s[i] - 'a'][0] = i;
            pos[s[i] - 'a'][1] = std::max(pos[s[i] - 'a'][1], i);
        }

        std::vector<int> res;
        int l = -1;
        int r = -1;
        for(int i = 0; i < n; i++) {
            r = std::max(r, pos[s[i] - 'a'][1]);
            if(i == r) {
                res.push_back(r - l);
                l = r;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "ababcbacadefegdehijhklij";
        std::vector<int> res = {9,7,8};
        assert(sol.partitionLabels(s) == res);
    }
    return 0;
}