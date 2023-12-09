#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int countBattleships(std::vector<std::vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'X')
                {
                    if((i - 1 >= 0 && board[i - 1][j] == 'X') || 
                       (j - 1 >= 0 && board[i][j - 1] == 'X'))continue;
                    res++;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> board = {{'X','.','.','X'},
                                                {'.','.','.','X'},
                                                {'.','.','.','X'}};
        int res = 2;
        assert(sol.countBattleships(board) == res);
    }
    {
        std::vector<std::vector<char>> board = {{'.'}};
        int res = 0;
        assert(sol.countBattleships(board) == res);
    }
    return 0;
}