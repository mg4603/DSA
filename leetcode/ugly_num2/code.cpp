#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        std::vector<int> table(n, 0);
        table[0] = 1;

        int x = 0;
        int y = 0; 
        int z = 0;

        for(int i = 1; i < n; i++)
        {
            table[i] = std::min(table[x] * 2, 
                                std::min(table[y] * 3,
                                         table[z] * 5));

            if(table[i] == table[x] * 2)x++;
            if(table[i] == table[y] * 3)y++;
            if(table[i] == table[z] * 5)z++;
        }
        return table[n - 1];
    }
};

int main()
{
    Solution sol;
    {
        int n = 10;
        int res = 12;
        assert(sol.nthUglyNumber(n) == res);
    }
    {
        int n = 1;
        int res = 1;
        assert(sol.nthUglyNumber(n) == res);
    }
    return 0;
}