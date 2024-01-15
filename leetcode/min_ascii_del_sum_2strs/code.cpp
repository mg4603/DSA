#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minimumDeleteSum(std::string s1, std::string s2) 
    {
        int n = s1.length();
        int m = s2.length();
        std::vector<std::vector<int>> table(n + 1, 
                                std::vector<int>(m + 1, 0));

        for(int i = 1; i < n + 1; i++)
        {
            table[i][0] = table[i - 1][0] + s1[i - 1] - 'a' + 97;
        }

        for(int i = 1; i < m + 1; i++)
        {
            table[0][i] = table[0][i-1] + s2[i - 1] - 'a' + 97;
        }

        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    table[i][j] = table[i - 1][j - 1];
                }
                else
                {
                    int temp1 = table[i-1][j] + s1[i - 1] + 97 - 'a'; 
                    int temp2 = table[i][j - 1] + s2[j - 1] + 97 - 'a'; 
                    table[i][j] = std::min(temp1, temp2);
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
        std::string s1 = "sea";
        std::string s2 = "eat";
        int res = 231;
        assert(sol.minimumDeleteSum(s1, s2) == res);
    }
    return 0;
}