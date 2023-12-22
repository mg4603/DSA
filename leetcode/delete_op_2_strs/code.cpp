#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) 
    {
        int n = word1.length();
        int m = word2.length();

        std::vector<std::vector<int>> table(n + 1, 
                            std::vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {

                if(word1[i-1] == word2[j-1])
                {
                    table[i][j] = 1 + table[i-1][j-1];
                }
                else
                {
                    table[i][j] = std::max(table[i - 1][j], 
                                            table[i][j - 1]);
                }
            }
        }

        return n + m - 2 * table[n][m];
    }
};

int main()
{
    Solution sol;
    {
        std::string word1 = "sea";
        std::string word2 = "eat";
        int res = 2;
        assert(sol.minDistance(word1, word2) == res);
    }
    {
        std::string word1 = "leetcode";
        std::string word2 = "etco";
        int res = 4;
        assert(sol.minDistance(word1, word2) == res);
    }
    return 0;
}