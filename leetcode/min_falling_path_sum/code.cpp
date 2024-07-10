#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        std::ios::sync_with_stdio(0);
        int n = matrix.size();
        int m = matrix.size();
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = matrix[i - 1][j];
                if(j - 1 >= 0){ 
                    temp = std::min(temp, matrix[i - 1][j - 1]);
                }
                if(j + 1 < m){ 
                    temp = std::min(temp, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += temp;
            }
        }
        return *(std::min_element(matrix[n - 1].begin(), 
                    matrix[n - 1].end()));
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>>  matrix = {{2,1,3},
                                                 {6,5,4},
                                                 {7,8,9}};
        int res = 13;
        assert(sol.minFallingPathSum(matrix) == res);
    }
    return 0;
}