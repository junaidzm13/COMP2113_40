#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//token = "R1", token_symbol = 'R'

/*This function searches the board to find the target's row and column indices*/
void search_token(string board[][15], string token, int &row_index, int &col_index){
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      for(int k = 0; k < board[i][j].length(); k++){
        if(board[i][j].substr(k, 2) == token){
          col_index = j;
          row_index = i;
          return;
        }
        k++;
      }
    }
  }
  row_index = -1;
  col_index = -1;
  return;
}

/*Given a board, player_number, dice_roll (singular), and a token's col and row indices as indexes
this function tells you at what position (col and row indices) this token will be at after
the move*/
void token_movement(int player_number, int dice_roll, int &row_index, int &col_index){
  int move1, move2, move3;
  if(row_index >= 6 && row_index <= 8){ //near player 1's home
    if(col_index < 6 && row_index == 6){
      move1 = min(5 - col_index, dice_roll);
      move2 = max(dice_roll - move1, 0);
      col_index = col_index + move1 + (move2 > 0);
      row_index = row_index - move2;
    }
    else if(col_index < 6 && row_index == 8){ //near to player1's home
      if(player_number == 1){
        move1 = min(col_index, dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        col_index = col_index - move1 + move3;
        row_index = row_index - move2;
      }
      else{
        move1 = min(col_index, dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        col_index = col_index - move1 + move3;
        row_index = row_index - move2;
      }
    }
    else if(col_index < 6 && row_index == 7){
      if(player_number == 1){
        row_index = row_index;
        if(dice_roll > 6 - col_index){
          col_index = col_index;
        }
        else{
          col_index = col_index + dice_roll;
        }
      }
      else{
        row_index = row_index - 1;
        col_index = col_index + dice_roll - 1;
      }
    }
    else if(col_index > 8 && row_index == 6){//near player 3's home
      if(player_number == 2){
        move1 = min(14 - col_index, dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        col_index = col_index + move1 - move3;
        row_index = row_index + move2;
      }
      else{
        move1 = min(14 - col_index, dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        col_index = col_index + move1 - move3;
        row_index = row_index + move2;
      }
    }
    else if(col_index > 8 && row_index == 8){
      move1 = min(col_index - 9, dice_roll);
      move2 = max(dice_roll - move1, 0);
      col_index = col_index - move1 - (move2 > 0);
      row_index = row_index + move2;
    }
    else if(col_index > 8 && row_index == 7){
      if(player_number == 2){
        row_index = row_index;
        if(dice_roll > col_index - 8){
          col_index = col_index;
        }
        else{
          col_index = col_index - dice_roll;
        }
      }
      else{
        row_index = row_index + 1;
        col_index = col_index - dice_roll + 1;
      }
    }
  }
  else if(col_index >= 6 && col_index <= 8){
    if(row_index < 6 && col_index == 8){ //near player2's home
      move1 = min(5 - row_index, dice_roll);
      move2 = max(dice_roll - move1, 0);
      row_index = row_index + move1 + (move2 > 0);
      col_index = col_index + move2;
    }
    else if(row_index < 6 && col_index == 6){
      if(player_number == 4){
        move1 = min(row_index, dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        row_index = row_index - move1 + move3;
        col_index = col_index + move2;
      }
      else{
        move1 = min(row_index, dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        row_index = row_index - move1 + move3;
        col_index = col_index + move2;
      }
    }
    else if(row_index < 6 && col_index == 7){
      if(player_number == 4){
        col_index = col_index;
        if(dice_roll > 6 - row_index){
          row_index = row_index;
        }
        else{
          row_index = row_index + dice_roll;
        }
      }
      else{
        col_index = col_index + 1;
        row_index = row_index + dice_roll - 1;
      }
    }
    else if(row_index > 8 && col_index == 8){
      if(player_number == 3){
        move1 = min(14 - row_index, dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        row_index = row_index + move1 - move3;
        col_index = col_index - move2;
      }
      else{
        move1 = min(14 - row_index, dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        row_index = row_index + move1 - move3;
        col_index = col_index - move2;
      }
    }
    else if(row_index > 8 && col_index == 6){
      move1 = min(row_index - 9, dice_roll);
      move2 = max(dice_roll - move1, 0);
      row_index = row_index - move1 - (move2 > 0);
      col_index = col_index - move2;
    }
    else if(row_index > 8 && col_index == 7){
      if(player_number == 3){
        col_index = col_index;
        if(dice_roll > row_index - 8){
          row_index = row_index;
        }
        else{
          row_index = row_index - dice_roll;
        }
      }
      else{
        col_index = col_index - 1;
        row_index = row_index - dice_roll + 1;
      }
    }
  }
}

/*Tells whether a particular token can be moved or not*/
bool can_move(string board[][15], int player_number, int dice_roll, int row_index, int col_index){
  bool can_be_moved;
  if((col_index < 6 && (row_index < 6 || row_index > 8)) || \ //in base or not
  (col_index > 8 && (row_index < 6 || row_index > 8))){
    if(dice_roll == 6){
      return 1;
    }
    else{
      return 0;
    }
  }
  can_be_moved = ! (col_index == 7 && (row_index == 6 || row_index == 8) || \ //has reached home or not
  row_index == 7 && (col_index == 6 || col_index == 8));
  int col_index2 = col_index, row_index2 = row_index;
  token_movement(player_number, dice_roll, row_index2, col_index2);
  return !(col_index == col_index2 && row_index == row_index2) && \
  can_be_moved; //else return 1
}

string will_kill(string board[][15], int player_number, string token, int dice_roll, \
  int row_index, int col_index){
    int col_index2 = col_index, row_index2 = row_index;
    bool land_at_home, land_at_star, not_on_empty, not_on_own_token, kills;
    token_movement(player_number, token, dice_roll, row_index2, col_index2);
    if(col_index2 == col_index && row_index2 == row_index){
      kills = 0;
    }
    else{
      land_at_star = ((col_index2 == 1 || col_index2 == 12) && row_index2 == 6 || \
        (col_index2 == 2 || col_index2 == 13) && row_index2 == 8 || \
        col_index2 == 6 && (row_index2 == 2 || row_index2 == 13) || \
        col_index2 == 8 && (row_index2 == 1 || row_index2 == 12));
      if(player_number == 1){
        land_at_home = (row_index2 == 7 && col_index2 > 0 && col_index2 <= 6);
        }
      else if(player_number == 4){
        land_at_home = (col_index2 == 7 && row_index2 > 0 && row_index2 <= 6);
      }
      else if(player_number == 2){
        land_at_home = (row_index2 == 7 && col_index2 >= 8 && col_index2 < 14);
      }
      else{
        land_at_home = (col_index2 == 7 && row_index2 >= 8 && row_index2 < 14)
      }
      not_on_empty = (board[row_index2][col_index2] != "xx" && board[row_index2][col_index2].length() == 2);
      not_on_own_token = board[row_index2][col_index2][0] != token[0];

      kills = (! land_at_star && ! land_at_home && not_on_empty && not_on_own_token);
    }
    if(kills == 1){
      return board[row_index2][col_index2];
    }
    else{
      return "";
    }
}

bool has_won(string board[][15], int player_number){
  if(player_number == 1){
    return board[7][6].length() == 8;
  }
  else if(player_number == 4){
    return board[6][7].length() == 8;
  }
  else if(player_number = 2){
    return board[7][8].length() == 8;
  }
  else{
    return board[8][7].length() == 8;
  }
}

/*IMPLEMENT YOUR MAKE MOVE FUNCTION HERE. MAKE USE OF THE ABOVE FUNCTIONS. DO NOT REPLICATE ANYTHING.*/
//void make_move(___){

//}
