#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) 
    {
        int n = s.length();

        std::vector<std::vector<int>> table(n + 1, 
                                std::vector<int>(n + 1, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(s[i] == s[j])
                {
                    table[i+1][n - j] = 1 + table[i][n-j-1]; 
                }
                else
                {
                    table[i + 1][n - j] = std::max(table[i + 1][n - j - 1],
                                                    table[i][n-j]);
                }
            }
        }
        return table[n][n];
    }
};

int main()
{
    Solution sol;
    
    {
        std::string s = "bbbab";
        int res = 4;
        assert(sol.longestPalindromeSubseq(s) == res);
    }
    {
        std::string s = "cbbd";
        int res = 2;
        assert(sol.longestPalindromeSubseq(s) == res);
    }
    return 0;
}