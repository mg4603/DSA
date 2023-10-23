#include <iostream>
#include <assert.h>

class Solution {
public:
    int minTimeToType(std::string word) {
        std::ios_base::sync_with_stdio(0);
        int n = word.length();
        int res = n;
        int current = 'a';
        for(int i = 0; i < n; i++)
        {
            int temp = std::abs(word[i] - current);
            res += std::min(temp, 26 - temp);
            current = word[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "abc";
        int res = 5;
        assert(sol.minTimeToType(word) == res);
    }
    {
        std::string word = "bza";
        int res = 7;
        assert(sol.minTimeToType(word) == res);
    }
    {
        std::string word = "zjpc";
        int res = 34;
        assert(sol.minTimeToType(word) == res);
    }
    return 0;
}