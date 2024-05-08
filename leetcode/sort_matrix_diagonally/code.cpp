#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> diagonalSort(
                std::vector<std::vector<int>>& mat) {
        std::ios::sync_with_stdio(0);
        int n = mat.size();
        int m = mat[0].size();
        std::vector<std::vector<int>> diags(n + m - 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                diags[n + j - i - 1].push_back(mat[i][j]);
            }
        }

        for(int i = 0; i < n + m - 1; i++) {
            std::sort(diags[i].begin(), diags[i].end(), 
                        std::greater<int>());
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mat[i][j] = diags[n + j - i - 1].back();
                diags[n + j - i - 1].pop_back();
            }
        }
        return mat;
    }
};

int main()
{
    return 0;
}