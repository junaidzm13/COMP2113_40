#include <iostream>
#include <string>
#include <cstdlib> //Ismail put this
#include <ctime> //Ismail put this
#include <string.h> //Ismail put this
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

//Ismail
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

struct Player_current_details{
  string username;
  char token;
  int player_number;
  string status;
  int rank;
};

//-----------------------------------------------------------------------------
//---------------------------SET_THE_BOARD-------------------------------------
//-----------------------------------------------------------------------------

void set_the_board(Player_current_details players[], int num_players, string board[][15]){
  //char Color;
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      if ((j==6|| j==7||j==8||i==6||i==7||i==8) && (j!=i) && (j+i!=14)){
        board[i][j]="xx";
      }
      else{
        board[i][j]="  ";
      }
    }
  }

  board[11][1]="31";
  board[11][3]="32";
  board[13][1]="33";
  board[13][3]="34";
  board[13][7]="3S";
  board[12][7]="3S";
  board[11][7]="3S";
  board[10][7]="3S";
  board[9][7]="3S";
  board[8][7]="3H";

  board[1][11]="41";
  board[1][13]="42";
  board[3][11]="43";
  board[3][13]="44";
  board[1][7]="4S";
  board[2][7]="4S";
  board[3][7]="4S";
  board[4][7]="4S";
  board[5][7]="4S";
  board[6][7]="4H";

  for (int i = 0; i < num_players; ++i){
    /*if (i == 0){
      Color = 'R';
    }
    else if (i==1){
      Color = 'Y';
    }
    else if (i == 2){
      Color = 'B';
    }else {
      Color = 'G';
    }
    players[i].token[0]=Color + '1';
    players[i].token[1]=Color + '2';
    players[i].token[2]=Color + '3';
    players[i].token[3]=Color + '4';*/
    string token = "";
    if (i == 0){
      token = token + players[i].token;
      //cout << player[i].username<<" is Red(R)"<<endl;
      //cout << player[1].username<<" is Yellow(Y)"<<endl;
      board[1][1]=token+"1";
      board[1][3]=token+"2";
      board[3][1]=token+"3";
      board[3][3]=token+"4";
      board[7][1]=token+"S";
      board[7][2]=token+"S";
      board[7][3]=token+"S";
      board[7][4]=token+"S";
      board[7][5]=token+"S";
      board[7][6]=token+"H";

    }
    else if (i == 1){
      token = "";
      token = token + players[i].token;
      board[11][11]=token+"1";
      board[11][13]=token+"2";
      board[13][11]=token+"3";
      board[13][13]=token+"4";
      board[7][13]=token+"S";
      board[7][12]=token+"S";
      board[7][11]=token+"S";
      board[7][10]=token+"S";
      board[7][9]=token+"S";
      board[7][8]=token+"H";
    }
    else if(i == 2){
      token = "";
      token = token + players[i].token;
      board[11][1]=token+"1";
      board[11][3]=token+"2";
      board[13][1]=token+"3";
      board[13][3]=token+"4";
      board[13][7]=token+"S";
      board[12][7]=token+"S";
      board[11][7]=token+"S";
      board[10][7]=token+"S";
      board[9][7]=token+"S";
      board[8][7]=token+"H";
    }
    else{
      token = "";
      token = token + players[i].token;
      board[1][11]=token+"1";
      board[1][13]=token+"2";
      board[3][11]=token+"3";
      board[3][13]=token+"4";
      board[1][7]=token+"S";
      board[2][7]=token+"S";
      board[3][7]=token+"S";
      board[4][7]=token+"S";
      board[5][7]=token+"S";
      board[6][7]=token+"H";
    }
    board[8][2]="SS";
    board[8][13]="SS";
    board[6][1]="SS";
    board[6][12]="SS";
    board[1][8]="SS";
    board[12][8]="SS";
    board[13][6]="SS";
    board[2][6]="SS";
  //  show_board(board);
  }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

string available_tokens(string user_tokens, string chosen_tokens, int size){
  string result = "";
  bool already_taken;
  for(int i = 0; i < user_tokens.length(); i++){
    already_taken = 0;
    for(int j = 0; j < size; j++){
      if(user_tokens[i] == chosen_tokens[j]){
        already_taken = 1;
      }
    }
    if(already_taken == 0){
      result = result + user_tokens[i];
    }
  }
  return result;
}

char select_token(string user_tokens, string chosen_tokens, int size){
  string result = "", available = available_tokens(user_tokens, chosen_tokens, size);
  string prompt = "Please select your token symbol from the following avaialble tokens:\n";
  char selection;
  bool right_selection = 0;
  for(int i = 0; i < available.length(); i++){
    if(i == available.length() - 1){
      result = result + available[i];
      continue;
    }
    result = result + available[i] + " ";
  }
  while(! right_selection){
    cout << prompt;
    cout << result << ": ";
    cin >> selection;
    for(int i = 0; i < available.length(); i++){
      if(selection == available[i]){
        right_selection = 1;
      }
    }
  }
  return selection;
}

bool read_username(string username){
  string word;
  int exists = 0;
  ifstream fin;
  fin.open("usernames.txt");
  while(fin >> word){
    if(word == username){
      exists = 1;
      return 1;
    }
  }
  fin.close();
  return 0;
}

//creates a new profile with username username
void create_new(string username){
  string filename = username + ".txt";
  ofstream fout;
  fout.open(filename.c_str());
  fout << username << endl;
  fout << 0 << endl; //level
  fout << 0 << endl; //XP
  fout << "YGRB" << endl; //available symbols
  fout << 0 << endl; //matches played
  fout << 0 << endl; //matches won
  fout << "0%" << endl; //winning percentage
  fout.close();
  fout.open("usernames.txt", ios::app);
  fout << username << endl;
  fout.close();
}

void load_profile(Profile &user, string username){
  int level, xp, played, won;
  string symbols, win_percentage, filename;
  ifstream fin;
  filename = username + ".txt";
  fin.open(filename.c_str());
  fin >> username;
  user.username = username;
  fin >> level;
  user.level = level;
  fin >> xp;
  user.xp = xp;
  fin >> symbols;
  user.token_symbols = symbols;
  fin >> played;
  user.played = played;
  fin >> won;
  user.won = won;
  fin >> win_percentage;
  user.win_percentage = win_percentage;
  fin.close();
}

string enter_username(){
  char createnew;
  string username;
  cout << "Please enter your username: ";
  cin >> username;
  while(read_username(username) != 1){
    cout << "No user found with that username.\nDo you want to create a new profile? (Y/N)" << endl;
    cin >> createnew;
    while(createnew != 'Y' && createnew != 'N'){
      cout << "Please press Y or N to continue: ";
      cin >> createnew;
    }
    if(createnew == 'N'){
      cout << "Please enter your username: ";
      cin >> username;
      continue;
    }
    else{
      create_new(username);
    }
  }
  cout << "Loading your profile " << username << "." << endl;
  return username;
}

//------------------------UPDATE_PROFILE-------------------------------------
//---------------------------------------------------------------------------
int getxp(int rank, int num_players){
  int xp;
  if(num_players == 2){
    if(rank == 1){
      xp = 2;
    }
    else if(rank == 2){
      xp = 0;
    }
  }
  else if(num_players == 3){
    if(rank == 1){
      xp = 3;
    }
    else{
      xp = 3 - rank;
    }
  }
  else{
    if(rank == 4){
      xp = 0;
    }
    else{
      xp = 7 - 2 * rank;
    }
  }
  return xp;
}

string tokens_unlock(int level){
  string token;
  switch (level){
    case 1:
    token = "";
    case 2:
    token = "#";
    break;
    case 3:
    token = "@";
    break;
    case 4:
    token = "!";
    break;
    case 5:
    token = "%";
    break;
    case 6:
    token = "$";
    break;
    case 7:
    token = "0";
    break;
    case 8:
    token = "J";
    break;
    case 9:
    token = "Q";
    break;
    case 10:
    token = "K";
    break;
    case 11:
    token = "A";
    break;
    default:
    token = "";
  }
  return token;
}

void update_profile(Profile username, int num_players, int rank){
  int newxp, newlevel, matches_played, matches_won, havewon, rank_counter;
  double win_percent, won, played;
  ofstream fout;
  string filename = username.username + ".txt";
  fout.open(filename.c_str());
  fout << username.username << endl;
  newxp = username.xp + getxp(rank, num_players);
  newlevel = newxp / 10 + 1;
  if(newlevel > username.level){
    cout << "Congratulations! " << username.username << " leveled up to " << newlevel << "!" << endl;
    if(newlevel <= 10){
      cout << "You have unlocked a new token symbol '" << tokens_unlock(newlevel) << "'!" << endl;
      username.token_symbols += tokens_unlock(newlevel);
    }
    cout << endl;
  }
  fout << newlevel << endl;
  fout << newxp << endl;
  fout << username.token_symbols << endl;
  username.played += 1;
  fout << username.played << endl;
  rank_counter = num_players + 1 - rank;
  havewon = (rank_counter > num_players / 2);
  username.won = username.won + havewon;
  fout << username.won << endl;
  won = username.won;
  played = username.played;
  win_percent = won / played * 100;
  fout << fixed << setprecision(2);
  fout << win_percent << "%" << endl;
  fout.close();
  return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

int main(){
  //Number of players
  int num_players = 0;
  while(num_players < 2 || num_players > 4){
    cout << "Please enter the number of players: (2, 3 or 4)" << endl;
    cin >> num_players;
  }
  //Ask for usernames. Ask for token symbols
  string username, chosen_tokens = "";
  Player_current_details * players_current_progress = new Player_current_details [num_players];
  Profile * players_profile = new Profile [num_players];
  for(int i = 0; i < num_players; i++){
    cout << "Player " << i << ":" << endl;
    username = enter_username();
    players_current_progress[i].player_number = i + 1;
    players_current_progress[i].username = username;
    load_profile(players_profile[i], username);
    players_current_progress[i].token = select_token(players_profile[i].token_symbols, \
      chosen_tokens, chosen_tokens.length());
    chosen_tokens = chosen_tokens + players_current_progress[i].token;
  }

  //-------------------------------------------------------------------------

  //Game_under_progress
  //-------------------------------------------------------------------------
  string board[15][15];
  set_the_board(players_current_progress, num_players, board);
  //printing the board
  //-------------------------------------------------------------------------
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      cout << setw(4) << board[i][j];
    }
    cout << endl;
  }
  //-------------------------------------------------------------------------


  //Testing-------------------------------------------------------------------
  /*char x = select_token("YGRB#", "YB", 2);
  cout << x << endl;
  */
  //---------------------------------------------------------------------------


  //After end of the game
  //---------------------TEST--------------------------------------------------
  for(int i = 0; i < num_players; i++){
    players_current_progress[i].rank = i + 1;
  }
  //---------------------------------------------------------------------------
  for(int i = 0; i < num_players; i++){
    update_profile(players_profile[i], num_players, \
      players_current_progress[i].rank);
  }
  cout << "End result:" << endl;
  for(int i = 0; i < num_players; i++){
    cout << "Player " << i + 1 << " (" << players_current_progress[i].username \
    << ") | Rank: " << players_current_progress[i].rank << endl;
  }
  //---------------------------------------------------------------------------
  delete [] players_current_progress;
  delete [] players_profile;
  return 0;
}
