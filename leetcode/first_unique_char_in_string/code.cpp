#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::vector<int> freq(26, 0);
        for(char ch: s)
        {
            freq[ch - 'a']++;
        }
        int idx(0);
        for(char ch: s)
        {
            if(freq[ch - 'a'] == 1)
            {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.firstUniqChar("leetcode") == 0);
        assert(sol.firstUniqChar("loveleetcode") == 2);
        assert(sol.firstUniqChar("aabb") == -1);
    }
    return 0;
}