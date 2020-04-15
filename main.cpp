#include <iostream>
#include <string>
using namespace std;
  int player_number, turn_count=0, dice_number=0, No_of_sixes=0;
  string board[15][15];
  cin >> player_number;
  string * player_name = new string [player_number];
  for (int i = 0; i < player_number; ++i){
    cin >> player_name[i];
  }
  while (0){
    if (turn_count == player_number){
      turn_count = 0;
    }
    dice_number = roll_dice(player_name, turn_count, player_number, No_of_sixes);
    boardd(player_name, turn_count, player_number, No_of_sixes, dice_number)
    turn_count++;

  }
}

