#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void dfs(std::vector<std::vector<char>> &board, 
             int i, int j, int n, int m)
    {
        if(i < 0 || j < 0 || 
           i >= n || j >= m || 
           board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = '#';
        dfs(board, i + 1, j, n, m);
        dfs(board, i - 1, j, n, m);
        dfs(board, i, j + 1, n, m);
        dfs(board, i, j - 1, n, m);
    }
public:
    void solve(std::vector<std::vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(board, i, 0, n, m);
            }
            if(board[i][m - 1] == 'O')
            {
                dfs(board, i, m - 1, n, m);
            }
        }

        for(int i = 1; i < m - 1; i++)
        {
            if(board[0][i] == 'O')
            {
                dfs(board, 0, i, n, m);
            }
            if(board[n - 1][i] == 'O')
            {
                dfs(board, n - 1, i, n, m);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> board = {{'X'}};
        std::vector<std::vector<char>> res = {{'X'}};
        sol.solve(board);
        assert(board == res);
    }
    {
        std::vector<std::vector<char>> board = {{'X','X','X','X'},
                                                {'X','O','O','X'},
                                                {'X','X','O','X'},
                                                {'X','O','X','X'}};
        std::vector<std::vector<char>> res = {{'X','X','X','X'},
                                              {'X','X','X','X'},
                                              {'X','X','X','X'},
                                              {'X','O','X','X'}};
        sol.solve(board);
        assert(board == res);
    }
    return 0;
}