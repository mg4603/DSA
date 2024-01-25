#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    double helper(int a, int b, 
                  std::vector<std::vector<double>> &table)
    {
        if(a <= 0 && b <= 0)return 0.5;
        if(b <= 0)return 0;
        if(a <= 0)return 1;
        if(table[a][b] != -1)return table[a][b];

        double res = 0.0;
        res += helper(a - 100, b, table);
        res += helper(a - 75, b - 25, table);
        res += helper(a - 50, b - 50, table);
        res += helper(a - 25, b - 75, table);
        table[a][b] = res * 0.25;
        return table[a][b];
    }
public:
    double soupServings(int n) {
        if(n > 4800)return 1;
        std::vector<std::vector<double>> table(n + 1, 
                        std::vector<double>(n + 1, -1));

        return helper(n, n, table);
    }
};

int main()
{
    Solution sol;
    {
        int n = 50;
        double res = 0.625;
        assert(sol.soupServings(n) == res);
    }
    return 0;
}