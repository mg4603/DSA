#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string customSortString(std::string order, std::string s) {
        std::vector<int> freq(26, 0);
        for(char &c: s) {
            freq[c - 'a']++;
        }

        std::string res;
        for(int i = 0; i < order.size(); i++) {
            int idx = order[i] - 'a';
            res += std::string(freq[idx], order[i]);
            freq[idx] = 0;
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0)continue;
            res += std::string(freq[i], i + 'a');
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string order = "cba";
        std::string s = "abcd";
        std::string res = "cbad";
        assert(sol.customSortString(order, s) == res);
    }
    return 0;
}