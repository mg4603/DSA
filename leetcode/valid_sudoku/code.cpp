#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) 
    {
        std::vector<std::vector<int>> rows(9, std::vector<int>(10, 0));
        std::vector<std::vector<int>> cols(9, std::vector<int>(10, 0));
        std::vector<std::vector<int>> boxes(9, std::vector<int>(10, 0));
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')continue;
                int temp = ++rows[i][board[i][j] - '0'];
                if(temp > 1)
                {
                    return false;
                }

                temp = ++ cols[j][board[i][j] - '0'];
                if(temp > 1)
                {
                    return false;
                }

                temp = ++boxes[(i / 3) * 3 + (j / 3)][board[i][j] - '0'];
                if(temp > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<char>> board = 
            {{'5','3','.','.','7','.','.','.','.'}
            ,{'6','.','.','1','9','5','.','.','.'}
            ,{'.','9','8','.','.','.','.','6','.'}
            ,{'8','.','.','.','6','.','.','.','3'}
            ,{'4','.','.','8','.','3','.','.','1'}
            ,{'7','.','.','.','2','.','.','.','6'}
            ,{'.','6','.','.','.','.','2','8','.'}
            ,{'.','.','.','4','1','9','.','.','5'}
            ,{'.','.','.','.','8','.','.','7','9'}};
        bool res = true;
        assert(sol.isValidSudoku(board) == res);
    }
    {
        std::vector<std::vector<char>> board = 
            {{'8','3','.','.','7','.','.','.','.'}
            ,{'6','.','.','1','9','5','.','.','.'}
            ,{'.','9','8','.','.','.','.','6','.'}
            ,{'8','.','.','.','6','.','.','.','3'}
            ,{'4','.','.','8','.','3','.','.','1'}
            ,{'7','.','.','.','2','.','.','.','6'}
            ,{'.','6','.','.','.','.','2','8','.'}
            ,{'.','.','.','4','1','9','.','.','5'}
            ,{'.','.','.','.','8','.','.','7','9'}};
        bool res = false;
        assert(sol.isValidSudoku(board) == res);
    }
    return 0;
}