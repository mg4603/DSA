#include <assert.h>
#include <iostream>

#include<string>
#include<vector>

std::string displayBoard(const std::vector<char>& board, unsigned short width){
  std::string res;
  for(int i(0); i < board.size(); i += width)
  {
    for(int j(0); j < width; j ++)
    {
      if(j != 0)
      {
        res += "|";
      }
      res += " ";
      res += board[i + j];
      res += " ";
    }
    if(i != board.size() - width)
    {
      res += "\n";
      res += std::string(3 * width + (width - 1), '-');
      res += "\n";
    }
  }
  
  return res;
}

int main()
{
    assert(displayBoard({'O', 'X', 'X', 'O'}, 2) == " O | X \n-------\n X | O ");
    assert(displayBoard({'O', 'X', ' ', ' ', 'X', ' ', 'X', 'O', ' '}, 3) == " O | X |   \n-----------\n   | X |   \n-----------\n X | O |   ");
    assert(displayBoard({'O', 'X', ' ', ' ', 'X', ' ', 'X', 'O', ' ', 'O'}, 5) == " O | X |   |   | X \n-------------------\n   | X | O |   | O ");
    assert(displayBoard({'O', 'X', ' ', ' ', 'X', ' ', 'X', 'O', ' ', 'O'}, 2) == " O | X \n-------\n   |   \n-------\n X |   \n-------\n X | O \n-------\n   | O ");
    assert(displayBoard({'1', '2', '3', '4', '5', '1', '2', '3', '4', '5', '1', '2', '3', '4', '5', '1', '2', '3', '4', '5', '1', '2', '3', '4', '5', '1', '2', '3', '4', '5', '1', '2', '3', '4', '5', '1'}, 6) == " 1 | 2 | 3 | 4 | 5 | 1 \n-----------------------\n 2 | 3 | 4 | 5 | 1 | 2 \n-----------------------\n 3 | 4 | 5 | 1 | 2 | 3 \n-----------------------\n 4 | 5 | 1 | 2 | 3 | 4 \n-----------------------\n 5 | 1 | 2 | 3 | 4 | 5 \n-----------------------\n 1 | 2 | 3 | 4 | 5 | 1 ");
    return 0;
};