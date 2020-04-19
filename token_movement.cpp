#include <iostream>
#include <string>
#include <cmath>
using namespace std;


//This function takes a board and player number (1, 2, 3, 4), the dice_roll and position (row & col index)
//It then tells if you move the player's token present at the given indexes by dice_roll, it then
//gives the new indexes of the token.
//FULLY TESTED
void token_movement(string board[][15], int player_number, int dice_roll, \
  int indexes[]){
  int move1, move2, move3;
  if(indexes[0] >= 6 && indexes[0] <= 8){ //near player 1's home
    if(indexes[1] < 6 && indexes[0] == 6){
      move1 = min(5 - indexes[1], dice_roll);
      move2 = max(dice_roll - move1, 0);
      indexes[1] = indexes[1] + move1 + (move2 > 0);
      indexes[0] = indexes[0] - move2;
    }
    else if(indexes[1] < 6 && indexes[0] == 8){ //near to player1's home
      if(player_number == 1){
        move1 = min(indexes[1], dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        indexes[1] = indexes[1] - move1 + move3;
        indexes[0] = indexes[0] - move2;
      }
      else{
        move1 = min(indexes[1], dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        indexes[1] = indexes[1] - move1 + move3;
        indexes[0] = indexes[0] - move2;
      }
    }
    else if(indexes[1] < 6 && indexes[0] == 7){
      if(player_number == 1){
        indexes[0] = indexes[0];
        if(dice_roll > 6 - indexes[1]){
          indexes[1] = indexes[1];
        }
        else{
          indexes[1] = indexes[1] + dice_roll;
        }
      }
      else{
        indexes[0] = indexes[0] - 1;
        indexes[1] = indexes[1] + dice_roll - 1;
      }
    }
    else if(indexes[1] > 8 && indexes[0] == 6){//near player 3's home
      if(player_number == 3){
        move1 = min(14 - indexes[1], dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        indexes[1] = indexes[1] + move1 - move3;
        indexes[0] = indexes[0] + move2;
      }
      else{
        move1 = min(14 - indexes[1], dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        indexes[1] = indexes[1] + move1 - move3;
        indexes[0] = indexes[0] + move2;
      }
    }
    else if(indexes[1] > 8 && indexes[0] == 8){
      move1 = min(indexes[1] - 9, dice_roll);
      move2 = max(dice_roll - move1, 0);
      indexes[1] = indexes[1] - move1 - (move2 > 0);
      indexes[0] = indexes[0] + move2;
    }
    else if(indexes[1] > 8 && indexes[0] == 7){
      if(player_number == 3){
        indexes[0] = indexes[0];
        if(dice_roll > indexes[1] - 8){
          indexes[1] = indexes[1];
        }
        else{
          indexes[1] = indexes[1] - dice_roll;
        }
      }
      else{
        indexes[0] = indexes[0] + 1;
        indexes[1] = indexes[1] - dice_roll + 1;
      }
    }
  }
  else if(indexes[1] >= 6 && indexes[1] <= 8){
    if(indexes[0] < 6 && indexes[1] == 8){ //near player2's home
      move1 = min(5 - indexes[0], dice_roll);
      move2 = max(dice_roll - move1, 0);
      indexes[0] = indexes[0] + move1 + (move2 > 0);
      indexes[1] = indexes[1] + move2;
    }
    else if(indexes[0] < 6 && indexes[1] == 6){
      if(player_number == 2){
        move1 = min(indexes[0], dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        indexes[0] = indexes[0] - move1 + move3;
        indexes[1] = indexes[1] + move2;
      }
      else{
        move1 = min(indexes[0], dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        indexes[0] = indexes[0] - move1 + move3;
        indexes[1] = indexes[1] + move2;
      }
    }
    else if(indexes[0] < 6 && indexes[1] == 7){
      if(player_number == 2){
        indexes[1] = indexes[1];
        if(dice_roll > 6 - indexes[0]){
          indexes[0] = indexes[0];
        }
        else{
          indexes[0] = indexes[0] + dice_roll;
        }
      }
      else{
        indexes[1] = indexes[1] + 1;
        indexes[0] = indexes[0] + dice_roll - 1;
      }
    }
    else if(indexes[0] > 8 && indexes[1] == 8){
      if(player_number == 4){
        move1 = min(14 - indexes[0], dice_roll);
        move2 = min(dice_roll - move1, 1);
        move3 = dice_roll - move1 - move2;
        indexes[0] = indexes[0] + move1 - move3;
        indexes[1] = indexes[1] - move2;
      }
      else{
        move1 = min(14 - indexes[0], dice_roll);
        move2 = min(dice_roll - move1, 2);
        move3 = dice_roll - move1 - move2;
        indexes[0] = indexes[0] + move1 - move3;
        indexes[1] = indexes[1] - move2;
      }
    }
    else if(indexes[0] > 8 && indexes[1] == 6){
      move1 = min(indexes[0] - 9, dice_roll);
      move2 = max(dice_roll - move1, 0);
      indexes[0] = indexes[0] - move1 - (move2 > 0);
      indexes[1] = indexes[1] - move2;
    }
    else if(indexes[0] > 8 && indexes[1] == 7){
      if(player_number == 4){
        indexes[1] = indexes[1];
        if(dice_roll > indexes[0] - 8){
          indexes[0] = indexes[0];
        }
        else{
          indexes[0] = indexes[0] - dice_roll;
        }
      }
      else{
        indexes[1] = indexes[1] - 1;
        indexes[0] = indexes[0] - dice_roll + 1;
      }
    }
  }
}

int main(){
  string array[15][15];
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      array[i][j] = "xx";
    }
  }
  array[3][8] = "R1";
  int position[2];
  position[0] = 8;
  position[1] = 1;
  token_movement(array, 1, 6, position);
  cout << position[0] << position[1] << endl;
}
