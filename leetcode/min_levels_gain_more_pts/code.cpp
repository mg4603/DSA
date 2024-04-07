#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minimumLevels(std::vector<int>& possible) {
        std::ios::sync_with_stdio(0);
        int n = possible.size();
        for(int i = 0; i < n; i++)
        {
            if(possible[i] == 0)possible[i] = -1;
            if(i > 0)possible[i] += possible[i - 1];
        }

        for(int i = 0; i < n - 1; i++)
        {
            if(2 * possible[i] > possible[n-1])
            {
                return i + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> possible = {1,0,1,0};
        int res = 1;
        assert(sol.minimumLevels(possible) == res);
    }
    return 0;
}