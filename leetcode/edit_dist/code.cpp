#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        std::vector<std::vector<int>> dist(n + 1, 
                                        std::vector<int>(m + 1, 0));
        for(int i = 1; i < n + 1; i++)
        {
            dist[i][0] = i;
        }
        for(int i = 1; i < m + 1; i++)
        {
            dist[0][i] = i;
        }

        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(word1[i - 1] != word2[j - 1])
                {
                    dist[i][j] = std::min(dist[i - 1][j], 
                                          std::min(dist[i][j - 1], 
                                          dist[i - 1][j - 1])) + 1;
                }
                else
                {
                    dist[i][j] = dist[i - 1][j - 1];
                }
            }
        }
        return dist[n][m];
    }
};

int main()
{
    Solution sol;
    {
        std::string word1 = "horse";
        std::string word2 = "ros";
        int res = 3;
        assert(sol.minDistance(word1, word2) == res);
    }
    {
        std::string word1 = "intention";
        std::string word2 = "execution";
        int res = 5;
        assert(sol.minDistance(word1, word2) == res);
    }
    return 0;
}