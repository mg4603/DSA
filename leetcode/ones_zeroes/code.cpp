#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) 
    {
        std::vector<std::vector<int>> table(m + 1, 
                                std::vector<int>(n + 1));

        for(std::string s: strs)
        {
            int zeros = std::count(s.begin(), s.end(), '0');
            int ones = s.length() - zeros;

            for(int i = m; i >= zeros; i--)
            {
                for(int j = n; j >= ones; j--)
                {
                    table[i][j] = std::max(table[i][j], 
                                    table[i - zeros][j - ones] + 1);
                }
            }
        }
        return table[m][n];
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> strs = {"10","0001","111001","1","0"};
        int m = 5;
        int n = 3;
        int res = 4;
        assert(sol.findMaxForm(strs, m, n) == res);
    }
        {
        std::vector<std::string> strs = {"10","0","1"};
        int m = 1;
        int n = 1;
        int res = 2;
        assert(sol.findMaxForm(strs, m, n) == res);
    }
    return 0;
}