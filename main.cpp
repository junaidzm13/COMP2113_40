int main(){
  int player_number, turn_count=0, dice_number=0, No_of_sixes=0;
  string board[15][15];
  cout << "Please input number of players" << endl;
  cin >> player_number;
  while(player_number>4){
    cout << "Number of players cannot be greater than 4" << endl;
    cout << "Please input number of players again" << endl;
    cin >> player_number;
  }
  string * player_name = new string [player_number];
  for (int i = 0; i < player_number; ++i){
    cout << "Please input the name of " << i+1<<" player." << endl;
    cin >> player_name[i];
  }
  set_the_board(player_name, player_number, board);




  while (0){
    if (turn_count == player_number){
      turn_count = 0;
    }
    dice_number = roll_dice(player_name, turn_count, No_of_sixes);
    boardd(player_name, turn_count, player_number, No_of_sixes, dice_number, board);
    turn_count++;

  }
}
