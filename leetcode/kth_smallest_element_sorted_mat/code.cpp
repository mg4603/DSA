#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        std::priority_queue<int> q;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(k > 0)
                {
                    k--;
                    q.push(matrix[i][j]);
                }
                else
                {
                    int temp = q.top();
                    if(temp > matrix[i][j])
                    {
                        q.pop();
                        q.push(matrix[i][j]);
                    }
                }
            }
        }
        
        return q.top();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
        int k = 8;
        int res = 13;
        assert(sol.kthSmallest(matrix, k) == res);
    }
    {
        std::vector<std::vector<int>> matrix = {{-5}};
        int k = 1;
        int res = -5;
        assert(sol.kthSmallest(matrix, k) == res);
    }
    return 0;
}