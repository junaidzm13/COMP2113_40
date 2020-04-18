#include <iostream>
#include <strings>
#include <algorithim>
using namespace std;

/*This function searches the board to find the target's row and column indices*/
void linear_search(string board[][15], string target, int &row_index, int &col_index){
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      if(string board[i][j] == target){
        col_index = j;
        row_index = i;
        return;
      }
    }
  }
  col_index = -1;
  row_index = -1;
  return;
}

/*Given a board, player_number, dice_roll (singular), and a token's col and row indices
this function tells you at what position (col and row indices) this token will be after
the move*/
void token_movement(string board[][15], int player_number, int dice_roll, \
  int &row_index, int &col_index){
  if(row_index >= 6 || row_index <= 8){
    if(col_index < 6 && row_index == 6){
      move1 = min(5 - col_index, dice_roll);
      move2 = min(dice_roll - move1, 0);
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
        if(dice_roll > 7 - col_index){
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
    else if(col_index > 8 && row_index == 6){
      if(player_number == 3){
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
      move2 = min(dice_roll - move1, 0);
      col_index = col_index - move1 - (move2 > 0);
      row_index = row_index + move2;
    }
    else if(col_index > 8 && row_index == 7){
      if(player_number == 3){
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
  else if(col_index >= 6 || col_index <= 8){
    if(row_index < 6 && col_index == 8){
      move1 = min(5 - row_index, dice_roll);
      move2 = min(dice_roll - move1, 0);
      row_index = row_index + move1 + (move2 > 0);
      col_index = col_index + move2;
    }
    else if(row_index < 6 && col_index == 6){
      if(player_number == 2){
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
      if(player_number == 2){
        col_index = col_index;
        if(dice_roll > 7 - row_index){
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
      if(player_number == 4){
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
      move2 = min(dice_roll - move1, 0);
      row_index = row_index - move1 - (move2 > 0);
      col_index = col_index - move2;
    }
    else if(row_index > 8 && col_index == 7){
      if(player_number == 4){
        col_index = col_index;
        if(dice_roll > row_index - 8){
          col_index = row_index;
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
bool can_move(string board[][15], int player_number, string token, int dice_roll){
  int col_index = -1, row_index = -1;
  linear_search(board[][15], token, player_number, row_index, col_index);
  if((col_index < 6 && (row_index < 6 || row_index > 8)) || \
  (col_index > 8 && (row_index < 6 || row_index > 8))){
    if(dice_roll == 6){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if(col_index == -1){
    return 0;
  }
  else{
    int col_index2 = col_index, row_index2 = row_index;
    token_movement(board[][15], dice_roll, row_index2, col_index2);
    if(board[row_index2][col_index2] == "*" || \
    board[row_index2][col_index2] == "xx"){
      return 1;
    }
    else if(board[row_index2][col_index2][0] >= '1' && \
      board[row_index2][col_index2][0] <= '4'){
      return 1;
    }
    else{
      return 0;
    }
  }
}
