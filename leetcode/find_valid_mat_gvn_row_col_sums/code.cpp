#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(
                            std::vector<int>& rowSum, 
                            std::vector<int>& colSum) {
        std::ios::sync_with_stdio(0);
        int n = rowSum.size();
        int m = colSum.size();
        std::vector<std::vector<int>> res(n, 
                        std::vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = std::min(rowSum[i], colSum[j]);
                res[i][j] = temp;
                rowSum[i] -= temp;
                colSum[j] -= temp;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> rowSum = {3,8};
        std::vector<int> colSum = {4,7};
        std::vector<std::vector<int>> res = {{3, 0},
                                             {1, 7}};
        assert(sol.restoreMatrix(rowSum, colSum) == res);
    }
    return 0;
}