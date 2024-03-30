#include <iostream>
#include <assert.h>

class Solution {
public:
    long long maximumSubsequenceCount(std::string text, 
                                    std::string pattern) {
        long long cnt0 = 1;
        long long cnt1 = 1;
        long long res0 = 0;
        long long res1 = 0;

        int n = text.length();
        for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
        {
            if(text[i] == pattern[1])
            {
                res0 += cnt0;
            }
            if(text[j] == pattern[0])
            {
                res1 += cnt1;
            }
            cnt0 += text[i] == pattern[0];
            cnt1 += text[j] == pattern[1];
        }
        return std::max(res0, res1);
    }
};

int main()
{
    Solution sol;
    {
        std::string text = "abdcdbc";
        std::string pattern = "ac";
        int res = 4;
        assert(sol.maximumSubsequenceCount(text, pattern) == res);
    }
    return 0;
}