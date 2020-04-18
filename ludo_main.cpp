#include <iostream>
#include <string>
using namespace std;

Struct Profile{
  string username;
  int level;
  int xp;
  string token_symbols;
  int played;
  int won;
  string win_percentage;
}

Struct current_traits{
  char token;
  int player_number;
  string status;
  int rank;
}

int main(){
  //Number of players
  int num_players = 0;
  while(num_players >= 2 && num_players <= 4){
    cout << "Please enter the number of players: (2,3 or 4)" << endl;
    cin >> num_players;
  }
  //Ask for usernames. Ask for token symbols
  current_traits array2[];
  current_traits * players_current_progress = tokens1[num_players];
  Profile array1[];
  Profile * players_profile = array1[num_players];
  for(int i = 1; i <= num_players; i++){
    username = enter_username();
    players_profile[i].player_number = i;
    load_profile(players_profile[i], username);
  }
  players_current_progress[0].token = 'Y';
  players_current_progress[1].token = 'G';
  players_current_progress[2].token = 'R';
  players_current_progress[3].token = 'B';
  //Set the board
  string board[15][15];
  set_the_board();
  show_board();

  //Show the board. Gives the player 1 the turn
  int num_players_won = 0;
  int i = 1, dice_roll;
  while(num_players_won != num_players - 1){
    cout << "Turn: " << players_profile.username << " (player " << i << ")" << endl;
    dice_roll = //dice roll function
    //make move function




    if(/*check_win()*/)
    {
      cout << players_profile.username << " (player " << i << ") won!" << endl;
      players_current_progress[i - 1].rank = num_players_won + 1;
      cout << "Rank: " << players_current_progress[i-1].rank << endl;
      num_players_won++;
    }
    if(i == 4){
      i = 0
    }
    i++;
  }

  //update_profile
  //play again??

}
