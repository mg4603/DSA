#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, 
                            std::string text2) {
        int n = text1.size();
        int m = text2.size();
        std::vector<std::vector<int>> table(n + 1, 
                                std::vector<int>(m + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(text1[i] == text2[j]) {
                    table[i + 1][j + 1] = table[i][j] + 1;
                }else {
                    table[i + 1][j + 1] = std::max(
                            table[i][j + 1], table[i + 1][j]);
                }

            }
        }        
        return table[n][m];
    }
};

int main()
{
    Solution sol;
    {
        std::string text1 = "abcde", text2 = "ace";
        int res = 3 ;
        assert(sol.longestCommonSubsequence(text1, text2) == res);
    }
    return 0;
}