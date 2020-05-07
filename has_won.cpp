#include <iostream>
#include <string>
#include "has_won.h"
using namespace std;

/*This function takes a 2-D string array representing a board and an integer representing
 the player number (1, 2, 3 or 4) and outputs a boolean whether the player has won or not.
 Player has won if all four tokens are accumulated at their respective home positions.*/
bool has_won(string board[][15], int player_number){
  if(player_number == 1){
    return board[7][6].length() == 8;
  }
  else if(player_number == 4){
    return board[6][7].length() == 8;
  }
  else if(player_number == 2){
    return board[7][8].length() == 8;
  }
  else{
    return board[8][7].length() == 8;
  }
}
