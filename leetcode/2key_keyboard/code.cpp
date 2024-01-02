#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minSteps(int n) {

        std::vector<int> table(n + 1);
        for(int i = 2; i <= n; i++)
        {
            table[i] = i;
            for(int j = i - 1; j > 1; j--)
            {
                if(i % j == 0)
                {
                    table[i] = table[j] + (i / j);
                    break;
                }
            }
        }
        return table[n];
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        int res = 3;
        assert(sol.minSteps(n) == res);
    }
    {
        int n = 1;
        int res = 0;
        assert(sol.minSteps(n) == res);
    }
    return 0;
}