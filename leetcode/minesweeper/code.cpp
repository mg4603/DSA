#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int getAdjacentMines(std::vector<std::vector<char>> &board, 
                         int x, int y, int n, int m)
    {
        int mines = 0;
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if((i == 0 && j == 0) || 
                   (x + i < 0) || 
                   (y + j < 0) || 
                   (x + i >= n) || 
                   (y + j >= m))continue;

                if(board[x + i][y + j] == 'M')
                {
                    mines++;
                }
            }
        }
        return mines;
    }
public:
    std::vector<std::vector<char>> updateBoard(
                    std::vector<std::vector<char>>& board, 
                    std::vector<int>& click) 
    {
        int n = board.size();
        int m = board[0].size();

        int x = click[0];
        int y = click[1];
        if(x >= n || y >= m || 
           x < 0 || y < 0 || 
           board[x][y] == 'B')return board;

        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
        }    
        else
        {
            int mines = getAdjacentMines(board, x, y, n, m);
            if(mines)
            {
                board[x][y] = mines + '0';
            }
            else
            {
                board[x][y] = 'B';
                for(int i = -1; i <= 1; i++)
                {
                    for(int j = -1; j <= 1; j++)
                    {
                        if((i == 0 && j == 0) || 
                           (x + i < 0) || (y + j < 0) || 
                           (x + i >= n) || (y + j >= m))continue;

                        if(board[x + i][y + j] == 'E')
                        {
                            click[0] += i;
                            click[1] += j;
                            updateBoard(board, click);
                            click[0] -= i;
                            click[1] -= j;
                        }
                    }
                }   
            }
            
        }
        return board;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> board = 
                        {{'E','E','E','E','E'},
                         {'E','E','M','E','E'},
                         {'E','E','E','E','E'},
                         {'E','E','E','E','E'}};
        std::vector<int> click = {3,0};

        std::vector<std::vector<char>> res = 
                        {{'B','1','E','1','B'},
                         {'B','1','M','1','B'},
                         {'B','1','1','1','B'},
                         {'B','B','B','B','B'}};
        
        assert(sol.updateBoard(board, click) == res);
    }
    return 0;
}