#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int cnt = 1;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        while(cnt <= n * n)
        {
            for(int i = left; i <= right; i++)
            {
                res[top][i] = cnt++;
            }
            if(++top > bottom)
            {
                break;
            }
            for(int i = top; i <= bottom; i++)
            {
                res[i][right] = cnt++;
            }
            if(--right < left)
            {
                break;
            }
            for(int i = right; i >= left; i--)
            {
                res[bottom][i] = cnt++;
            }
            if(--bottom < top)
            {
                break;
            }
            for(int i = bottom; i >= top; i--)
            {
                res[i][left] = cnt++;
            }
            if(++left > right)
            {
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 3;
        std::vector<std::vector<int>> res = {{1,2,3},{8,9,4},{7,6,5}};
        assert(sol.generateMatrix(n) == res);
    }
     {
        int n = 1;
        std::vector<std::vector<int>> res = {{1}};
        assert(sol.generateMatrix(n) == res);
    }
    return 0;
}