#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int orderOfLargestPlusSign(int n, 
                std::vector<std::vector<int>>& mines) {
        std::vector<std::vector<int>> board(n, 
                            std::vector<int>(n, 1));

        for(auto mine: mines)
        {
            board[mine[0]][mine[1]] = 0;
        }

        std::vector<std::vector<int>> left, right, top, bottom;
        left = right = top = bottom = board;

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
            {
                int x = n - r - 1;
                int y = n - c - 1;
                if(c > 0 && 
                    board[r][c])left[r][c] += left[r][c - 1];

                if(r > 0 && 
                    board[r][c])top[r][c] += top[r - 1][c];


                if(x < n - 1 && 
                    board[x][y])bottom[x][y] += bottom[x + 1][y];

                if(y < n - 1 && 
                    board[x][y])right[x][y] += right[x][y + 1];

            }
        }

        int res = 0;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
            {
                res = std::max(res, 
                        std::min({left[r][c], 
                                    top[r][c], 
                                    bottom[r][c], 
                                    right[r][c]}));
            }
        }
       
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 5;
        std::vector<std::vector<int>> mines = {{4,2}};
        int res = 2;
        assert(sol.orderOfLargestPlusSign(n, mines) == res);
    }
    return 0;
}