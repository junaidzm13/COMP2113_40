struct cordinates{
  int x;
  int y;
};

struct Profile{
  string username;
  int level;
  int xp;
  string token_symbols;
  int played;
  int won;
  string win_percentage;
};
struct player_details{
  string username;    //
  string token[4];      //
  int player_position;
  string status;
  int rank;
};

int main(){
  int player_number;
  int turn_count=0;
  int dice_number=0;
  int No_of_sixes = 0;
  cout << "Please input number of players" << endl;
  string board[15][15];
  cin >> player_number;
  while(player_number>4){
    cout << "Number of players cannot be greater than 4" << endl;
    cout << "Please input number of players again" << endl;
    cin >> player_number;
  }
  while(player_number<2){
    cout << "Number of players cannot be less than 2" << endl;
    cout << "Please input number of players again" << endl;
    cin >> player_number;
  }

  player_details *player = new player_details[player_number];
  for (int i = 0; i < player_number; ++i){
    cout << "Please input the name of " << i+1<<" player." << endl;
    cin >> player[i].username;
  }

  show_board(board);
  set_the_board(player, player_number, board);



  for (int i=0; i<10; ++i){   //this will change on depending on No of players remaining after every move, 
    if (turn_count == player_number){
      turn_count = 0;
    }
    cout << player[turn_count].username<< "'s turn" << endl;
    dice_number = roll_dice(player, turn_count, No_of_sixes, dice_number);
    if (dice_number != 0){
      cout << dice_number<< endl;
      make_a_move(player, turn_count, player_number, No_of_sixes, dice_number, board);
    }
    No_of_sixes=0;
    dice_number=0;
    turn_count++;
  }

}
