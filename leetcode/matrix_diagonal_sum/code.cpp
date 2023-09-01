#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat) {
        int n(mat.size());
        int sum(0);
        if(n % 2 == 1)
        {
            sum = -mat[n/2][n/2];
        }
        for(int i(0); i < n; i++)
        {
            sum += mat[i][i];
            sum += mat[n - i - 1][i];
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> mat = {{1,2,3},
                                            {4,5,6},
                                            {7,8,9}};
        assert(sol.diagonalSum(mat) == 25);
    }
    {
        std::vector<std::vector<int>> mat = {{1,1,1,1},
                                             {1,1,1,1},
                                             {1,1,1,1},
                                             {1,1,1,1}};
        assert(sol.diagonalSum(mat) == 8);
    }
    {
        std::vector<std::vector<int>> mat = {{5}};
        assert(sol.diagonalSum(mat) == 5);
    }
    return 0;
}