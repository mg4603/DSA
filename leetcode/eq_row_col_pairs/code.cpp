#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        std::ios::sync_with_stdio(0);
        std::map<std::vector<int>, int> rows;
        std::map<std::vector<int>, int> cols;
        int n = grid.size();
        int res = 0;

        for(int i = 0; i < n; i++) {
            res += cols[grid[i]];
            rows[grid[i]]++;
            std::vector<int> col;
            for(int j = 0; j < n; j++) {
                col.push_back(grid[j][i]);
            }
            res += rows[col];
            cols[col]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> grid = {{3,2,1},{1,7,6},
                                                {2,7,7}};
        int res = 1;
        assert(sol.equalPairs(grid) == res);
    }
    return 0;
}