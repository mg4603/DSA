#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

bool verticalFour(std::vector<std::vector<std::string>> board, std::string color, int row, int col)
{
    if(row < 3){
        return false;
    }
    for(int i(row), cnt(4); cnt-- > 0; i--){
        if(board[col][i] != color)
        {
            return false;
        }
    }
    
    return true;
}

bool horizontalFour(std::vector<std::vector<std::string>> board, std::string color, int row, int col)
{

    int cnt(0);
    int start_col(col);
    int end_col(col);
    while(start_col)
    {
        start_col --;
    }
    while(end_col < board.size())
    {
        end_col ++;
    }

    for(int i(start_col); i < end_col; i++)
    {
        if(board[i][row] == color)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        if(cnt == 4)
        {
            return true;
        }    

    }

    return false;
}

bool primaryDiagFour(std::vector<std::vector<std::string>> board, std::string color, int row, int col)
{

    int cnt(0);
    int start_row(row);
    int end_row(row);
    int start_col(col);
    int end_col(col);
    while(start_row && start_col){
        start_row--;
        start_col--;
    }
    while(end_row < board[0].size() && end_col < board.size())
    {
        end_row++;
        end_col++;
    }
    for(int i(start_row), j(start_col); i < (end_row) && j < (end_col); i++, j++)
    {
        if(board[j][i] == color)
        {
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt == 4)
        {
            return true;
        }
    }
    
    return false;
}

bool secondDiagFour(std::vector<std::vector<std::string>> board, std::string color, int row, int col)
{

    int cnt(0);
    int start_row(row);
    int end_row(row);
    int start_col(col);
    int end_col(col);
    while(start_row && start_col < board.size() - 1){
        start_row--;
        start_col++;
    }
    while(end_row < board[0].size() && end_col)
    {
        end_row++;
        end_col--;
    }
    for(int i(start_row), j(start_col); i <= (end_row) && j >= 0; i++, j--)
    {
        if(board[j][i] == color)
        {
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt == 4)
        {
            return true;
        }
    }
 
    return false;
}

void drawBoard(std::vector<std::vector<std::string>> board)
{
    for(size_t j(0); j < board[0].size(); j++)
    {
        for(size_t i(0); i < board.size(); i++)
        {
            if(board[i][j] == "")
              std::cout<<' ';
            std::cout<<board[i][j][0]<<' ';
        }
        std::cout<<std::endl;
    }
}

bool hasWon(std::vector<std::vector<std::string>> board, std::string color, int row, int col)
{   
    return verticalFour(board, color, row, col) || 
            horizontalFour(board, color, row, col) ||
            primaryDiagFour(board, color, row, col) ||
            secondDiagFour(board, color, row, col);
}

std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    std::vector<std::vector<std::string>> board('G' - 'A' + 1, std::vector<std::string>(6, ""));
    for(auto pos: pieces_position_list)
    {
        char column = pos[0] - 'A';
        std::string color = pos.substr(pos.find('_') + 1);
        std::vector<std::string>::iterator it = std::find(board[column].begin(), board[column].end(), "");
        *it = color;
        if(hasWon(board, color, it - board[column].begin(), column))
        {
            return color;
        }
    }
    return "Draw";
}


int main()
{
    assert(who_is_winner( {
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "G_Red",
            "B_Yellow"
    }) == "Yellow");
    assert(who_is_winner( {
            "C_Yellow",
            "E_Red",
            "G_Yellow",
            "B_Red",
            "D_Yellow",
            "B_Red",
            "B_Yellow",
            "G_Red",
            "C_Yellow",
            "C_Red",
            "D_Yellow",
            "F_Red",
            "E_Yellow",
            "A_Red",
            "A_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "F_Yellow",
            "D_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "A_Red",
            "G_Yellow",
            "D_Red",
            "D_Yellow",
            "C_Red"
    }) == "Yellow");
    assert(who_is_winner( {
            "A_Yellow",
            "B_Red",
            "B_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "C_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "F_Yellow",
            "E_Red",
            "D_Yellow"
    }) == "Red");
    assert(who_is_winner( {
            "F_Yellow",
            "G_Red",
            "D_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "E_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "B_Yellow",
            "E_Red",
            "C_Yellow",
            "D_Red",
            "F_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "G_Yellow",
            "C_Red",
            "F_Yellow",
            "E_Red",
            "A_Yellow",
            "A_Red",
            "C_Yellow",
            "B_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "G_Red",
            "A_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "B_Yellow",
            "E_Red",
            "F_Yellow",
            "G_Red",
            "G_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red"
    }) == "Red");
    assert(who_is_winner( {
            "C_Yellow",
            "B_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "G_Red",
            "B_Yellow",
            "G_Red",
            "E_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "D_Yellow",
            "B_Red",
            "G_Yellow",
            "A_Red",
            "F_Yellow",
            "B_Red",
            "D_Yellow",
            "A_Red",
            "F_Yellow",
            "F_Red",
            "B_Yellow",
            "F_Red",
            "F_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "C_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "D_Yellow",
            "D_Red",
            "E_Yellow",
            "D_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "E_Red"
    }) == "Yellow");

    assert(who_is_winner({
            "C_Red",
            "G_Yellow",
            "D_Red",
            "D_Yellow",
            "E_Red",
            "G_Yellow",
            "G_Red",
            "B_Yellow",
            "D_Red",
            "F_Yellow",
            "F_Red",
            "F_Yellow",
            "F_Red",
            "E_Yellow",
            "G_Red",
            "A_Yellow",
            "D_Red",
            "F_Yellow",
            "B_Red",
            "G_Yellow",
            "C_Red",
            "D_Yellow",
            "A_Red",
            "C_Yellow",
            "E_Red",
            "B_Yellow",
            "C_Red",
            "A_Yellow",
            "B_Red",
            "E_Yellow",
            "B_Red",
            "D_Yellow",
            "A_Red",
            "F_Yellow",
            "E_Red",
    }) == "Yellow");

    assert(who_is_winner({
            "D_Yellow",
            "E_Red",
            "E_Yellow",
            "G_Red",
            "E_Yellow",
            "D_Red",
            "G_Yellow",
            "A_Red",
            "G_Yellow",
            "F_Red",
            "E_Yellow",
            "E_Red",
            "C_Yellow",
            "C_Red",
            "C_Yellow",
            "B_Red",
            "B_Yellow",
            "D_Red",
            "D_Yellow",
            "G_Red",
            "F_Yellow",
            "A_Red",
            "A_Yellow",
            "E_Red",
            "G_Yellow",
            "B_Red",
            "G_Yellow",
            "A_Red",
            "A_Yellow",
            "F_Red",
            "C_Yellow",
    }) == "Draw");
    return 0;
}