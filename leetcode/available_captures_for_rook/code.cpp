#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numRookCaptures(std::vector<std::vector<char>>& board) {
        int x_rook = 0;
        int y_rook = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == 'R')
                {
                    x_rook = i;
                    y_rook = j;
                }
            }
        }
        int captures(0);
        for(int i = x_rook + 1; i < 8; i++)
        {
            if(board[i][y_rook] == 'p')
            {
                captures++;
                break;
            }
            else if(board[i][y_rook] == 'B')
            {
                break;
            }
        }

        for(int i = x_rook - 1; i >= 0; i--)
        {
            if(board[i][y_rook] == 'p')
            {
                captures++;
                break;
            }
            else if(board[i][y_rook] == 'B')
            {
                break;
            }
        }

        for(int j = y_rook + 1; j < 8; j++)
        {
            if(board[x_rook][j] == 'p')
            {
                captures++;
                break;
            }
            else if(board[x_rook][j] == 'B')
            {
                break;
            }
        }

        for(int j = y_rook - 1; j >= 0; j--)
        {
            if(board[x_rook][j] == 'p')
            {
                captures++;
                break;
            }
            else if(board[x_rook][j] == 'B')
            {
                break;
            }
        }
        return captures;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> board = {
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','R','.','.','.','p'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
        };
        int res = 3;
        assert(sol.numRookCaptures(board) == res);
    }
    {
        std::vector<std::vector<char>> board = {
            {'.','.','.','.','.','.','.','.'},
            {'.','p','p','p','p','p','.','.'},
            {'.','p','p','B','p','p','.','.'},
            {'.','p','B','R','B','p','.','.'},
            {'.','p','p','B','p','p','.','.'},
            {'.','p','p','p','p','p','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'}
        };
        int res = 0;
        assert(sol.numRookCaptures(board) == res);
    }
    {
        std::vector<std::vector<char>> board = {
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'p','p','.','R','.','p','B','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','B','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
        };
        int res = 3;
        assert(sol.numRookCaptures(board) == res);
    }
    return 0;
}