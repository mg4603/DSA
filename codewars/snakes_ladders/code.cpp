#include <iostream>
#include <assert.h>

#include <iostream>
class SnakesLadders
{
  int turn;
  int player1Pos;
  int player2Pos;
  public:
    SnakesLadders(){
      this->player1Pos = 0;
      this->player2Pos = 0;
      this->turn = 1;
    };
    int newPos(int pos, int move){
          pos += move;
          if (pos > 100){
            pos = 100 - (pos % 100);
          }
          switch(pos){
              case 2:
                return 38;
              case 7:
                return 14;
              case 8:
                return 31;
              case 15:
                return 26;
              case 16:
                return 6;
              case 21:
                return 42;
              case 28:
                return 84;
              case 36:
                return 44;
              case 46:
                return 25;
              case 49:
                return 11;
              case 51:
                return 67;
              case 62:
                return 19;
              case 64:
                return 60;
              case 71:
                return 91;
              case 74:
                return 53;
              case 78:
                return 98;
              case 87:
                return 94;
              case 89:
                return 68;
              case 92:
                return 88;
              case 95:
                return 75;
              case 99:
                return 80;
              default:
                return pos;
                
          }
    }
    void changeTurn(){
      if (this->turn == 1){
        this->turn = 2;
      }else{
        this->turn = 1;
      }
    }
    bool gameOver(){
      if (this->player1Pos == 100 || this->player2Pos == 100)
        return true;
      return false;
    }
    std::string play(int die1, int die2)
    {
      if(this->gameOver())
        return "Game over!";
      
      if(this->turn == 1){
        this->player1Pos = this->newPos(this->player1Pos, die1 + die2);
        
        if(this->player1Pos == 100)
          return "Player 1 Wins!";
        
        if (die1 != die2)
          this->changeTurn();
        return "Player 1 is on square " + std::to_string(this->player1Pos); 
        
      }else{
        this->player2Pos = this->newPos(this->player2Pos, die1 + die2);
        
        if (this->player2Pos == 100)
          return "Player 2 Wins!";
        
        if (die1 != die2)
          this->changeTurn();
        return "Player 2 is on square " +std::to_string(this->player2Pos);
      }
      
    };
};

int main(){
    SnakesLadders game = SnakesLadders();

    assert(game.play(1,1) == "Player 1 is on square 38");
    assert(game.play(1,5) == "Player 1 is on square 44");
    assert(game.play(6,2) == "Player 2 is on square 31");
    assert(game.play(1,1) == "Player 1 is on square 25");
    return 0;
}