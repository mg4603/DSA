#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Solution {
public:
    int kthLargestValue(std::vector<std::vector<int>>& matrix, int k) {
        std::ios::sync_with_stdio(0);
        int n = matrix.size();
        int m = matrix[0].size();

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i)matrix[i][j] ^= matrix[i - 1][j];
                if(j)matrix[i][j] ^= matrix[i][j - 1];
                if(i && j)matrix[i][j] ^= matrix[i - 1][j - 1];
                pq.push(matrix[i][j]);
                if(pq.size() > k)pq.pop();
            }
        }         
             
        return pq.top();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = {{5,2},{1,6}};
        int k = 1;
        int res = 7;
        assert(sol.kthLargestValue(matrix, k) == res);
    }
    return 0;
}