#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        std::vector<std::vector<int>> new_board(n, 
                                            std::vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int live_neighbors = 0;
                for(int k = -1; k <= 1; k++)
                {
                    if(i + k < 0 || i + k >= n)continue;

                    for(int l = -1; l <= 1; l++)
                    {
                        if(j + l < 0 || 
                           j + l >= m || 
                           (l == 0 && k == 0))continue;
                        if(board[i+k][j+l] == 1)
                        {
                            live_neighbors++;
                        }
                    }
                }
                if(board[i][j] == 1)
                {
                    if(!(live_neighbors  < 2 || 
                         live_neighbors > 3))
                    {
                        new_board[i][j] = 1;
                    }
                }
                else
                {
                    if(live_neighbors == 3)
                    {
                        new_board[i][j] = 1;
                    }
                }
            }
        }
        board = new_board;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> board = {{0,1,0},
                                               {0,0,1},
                                               {1,1,1},
                                               {0,0,0}};

        std::vector<std::vector<int>> res = {{0,0,0},
                                             {1,0,1},
                                             {0,1,1},
                                             {0,1,0}};
        sol.gameOfLife(board);
        assert(board == res);
    }
    {
        std::vector<std::vector<int>> board = {{1,1},
                                               {1,0}};

        std::vector<std::vector<int>> res = {{1,1},
                                             {1,1}};
        sol.gameOfLife(board);
        assert(board == res);
    }
    return 0;
}