#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool checkWon(std::vector<std::vector<char>> board)
    {
        int n = board.size();

        for(int i = 0; i < n; i++)
        {
            char temp = board[i][0];
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != ' ' && temp == board[i][j])
                {
                    count++;
                }
            }
            if(count == n)
            {

                return true;
            }
        }

        for(int j = 0; j < n; j++)
        {
            char temp = board[0][j];
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                if(board[i][j] != ' ' && temp == board[i][j])
                {
                    count++;
                }
            }
            if(count == n)
            {
                return true;
            }
        }

        char temp = board[0][0];
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(board[i][i] != ' ' && board[i][i] == temp)
            {
                count++;
            }
        }
        if(count == n)
        {

            return true;
        }

        temp = board[0][n-1];
        count = 0;
        for(int i = 0; i < n; i++)
        {
            if(board[i][n - i - 1] != ' ' && board[i][n - i - 1] == temp )
            {
                count++;
            }
        }
        if(count == n)
        {
            return true;
        }
        return false;
    }
public:
    std::string tictactoe(std::vector<std::vector<int>>& moves) {
        std::vector<std::vector<char>> board = std::vector<std::vector<char>>(
                                                3, std::vector<char>(3, ' '));
        char current = 'A';
        for(int i = 0; i < moves.size(); i++)
        {
            
            board[moves[i][0]][moves[i][1]] = current;
            if(checkWon(board))
            {
                return std::string(1, current);
            }
            if(current == 'A')
            {
                current = 'B';
            }
            else
            {
                current = 'A';
            }
        }
        if(moves.size() == 9)
        {
            return "Draw";
        }
        return "Pending";
    }
};
int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> moves = {
            {0,0},{2,0},{1,1},{2,1},{2,2}
        };
        std::string res = "A";
        assert(sol.tictactoe(moves) == res);
    }
    {
        std::vector<std::vector<int>> moves = {
            {0,0},{1,1},{0,1},{0,2},{1,0},{2,0}
        };
        std::string res = "B";
        assert(sol.tictactoe(moves) == res);
    }
    {
        std::vector<std::vector<int>> moves = {
            {0,0},{1,1},{2,0},{1,0},{1,2},
            {2,1},{0,1},{0,2},{2,2}
        };
        std::string res = "Draw";
        assert(sol.tictactoe(moves) == res);
    }
    return 0;
}