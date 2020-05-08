#include <iostream>
#include <string>
#include <iomanip>
#include "read_username.h"
#include "load_profile.h"
#include "update_profile.h"
#include "select_token.h"
#include "has_won.h"
#include "set_the_board.h"
#include "show_board.h"
#include "make_a_move.h"
#include "roll_dice.h"
#include "output_profile.h"
#include "structs.h"
using namespace std;

int main(){
  //Number of players
  int num_players = 0;
  while(num_players < 2 || num_players > 4){
    cout << "Please enter the number of players: (2, 3 or 4)" << endl;
    cout << "Number of players can only be two, three, or four."<<endl;
    cin >> num_players;
  }
  //Ask for usernames. Ask for token symbols. Populate structure arrays.
  string username, chosen_tokens = "";
  Player_current_details * players_current_progress = new Player_current_details [num_players];
  Profile * players_profile = new Profile [num_players];
  for(int i = 0; i < num_players; i++){
    cout << "Player " << i + 1 << ":" << endl;
    username = enter_username(players_current_progress, i);
    players_current_progress[i].player_number = i + 1;
    players_current_progress[i].username = username;
    load_profile(players_profile[i], username);
    players_current_progress[i].token = select_token(players_profile[i].token_symbols, \
      chosen_tokens);
    chosen_tokens = chosen_tokens + players_current_progress[i].token;
    players_current_progress[i].rank = num_players;
  }

  //Game_under_progress
  //-------------------------------------------------------------------------
  int turn_count = 0;   //0 means player 1
  int dice_number = 0; //dice roll other than 6
  int No_of_sixes = 0; //number of sixes
  string board[15][15];

  set_the_board(players_current_progress, num_players, board);
  show_board(board, players_current_progress, num_players);

  int Num_player_won = 0;
  while (Num_player_won < num_players-1){
    if (turn_count == num_players){
      turn_count = 0;
    }
    if(has_won(board, turn_count + 1)){
      turn_count++;
      continue;
    }
    cout << players_current_progress[turn_count].username<< "\'s turn" << endl;
    dice_number = roll_dice(players_current_progress, turn_count, No_of_sixes, dice_number);

    if (dice_number != 0){
      cout << dice_number<< endl;
      make_a_move(players_current_progress, turn_count, num_players, No_of_sixes, dice_number, board);
    }
    else{
      show_board(board, players_current_progress, num_players);
    }
    if (has_won(board, turn_count + 1)){
      Num_player_won += 1;
      cout << "Congratulations " << players_current_progress[turn_count].username << \
      "!!! Your rank is " << Num_player_won;
      cout << "! :)" << endl;
      players_current_progress[turn_count].rank = Num_player_won;
    }
    No_of_sixes = 0;
    dice_number = 0;
    turn_count++;
  }
  //Game ended
  cout << endl << setfill('-') << right << setw(50) << "" << endl;
  cout << setfill('-') << right << setw(30) << "GAME ENDED!" << setw(20) << "" << endl;
  cout << setfill('-') << right << setw(31) << "WELL PLAYED!" << setw(19) << "" << endl;
  cout << setfill('-') << right << setw(50) << "" << endl << endl;

  //-------------------------------UPDATING RESULTS--------------------------------------------
  cout << setfill('*') << right << setw(21) << "END RESULT" << setw(11) << "" << endl;
  for(int i = 0; i < num_players; i++){
    cout << setfill(' ') << left << setw(7) << "Player " << setw(1) << i + 1 << setw(14) << " (" + \
    players_current_progress[i].username.substr(0, 10) + ") ";
    cout << setfill(' ') << left << setw(7) << "| RANK: " << setw(2) << players_current_progress[i].rank << endl;
  }
  cout << endl << endl << setfill('*') << right << setw(20) << "UPDATED PROFILES" << setw(4) << "" << endl;
  for(int i = 0; i < num_players; i++){
    update_profile(players_profile[i], num_players, \
      players_current_progress[i].rank);
    cout << endl << "Player " << i + 1 << endl;
    output_profile(players_profile[i]);
  }

  delete [] players_current_progress;
  delete [] players_profile;
  return 0;
}
