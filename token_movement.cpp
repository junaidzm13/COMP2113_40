#include <iostream>
#include <strings>
#include <algorithim>
using namespace std;

void token_movement(string board[][15], int player_number, int dice_roll, \
  int indexes[]){
  if( >= 6 || indexes[0] <= 8){
    if(indexes[1] < 6 && indexes[0] == 6){
      move1 = min(5 - indexes[1], dice_roll);
      move2 = min(dice_roll - move1, 0);
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
        if(dice_roll > 7 - indexes[1]){
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
    else if(indexes[1] > 8 && indexes[0] == 6){
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
      move2 = min(dice_roll - move1, 0);
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
  else if(indexes[1] >= 6 || indexes[1] <= 8){
    if(indexes[0] < 6 && indexes[1] == 8){
      move1 = min(5 - indexes[0], dice_roll);
      move2 = min(dice_roll - move1, 0);
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
        if(dice_roll > 7 - indexes[0]){
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
      move2 = min(dice_roll - move1, 0);
      indexes[0] = indexes[0] - move1 - (move2 > 0);
      indexes[1] = indexes[1] - move2;
    }
    else if(indexes[0] > 8 && indexes[1] == 7){
      if(player_number == 4){
        indexes[1] = indexes[1];
        if(dice_roll > indexes[0] - 8){
          indexes[1] = indexes[0];
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
