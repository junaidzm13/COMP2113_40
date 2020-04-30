#include <iostream>
#include <string>
#include <cstdlib> //Ismail put this
#include <ctime> //Ismail put this
#include <string.h> //Ismail put this
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

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
  string username;    //
  char token;      //
  int player_number;
  string status;
  int rank;
};

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




void show_board(string board[][15]){
  int duplicate_places = 0;
  int stop = 0;
  char stop_or_not[8];
  cordinates arr[8]; //

  for (int i = 0; i < 15; ++i){
    for (int j = 0; j < 15; ++j){
      if ( (i == 8 && j == 2) || (i == 8 && j == 13 ) || (i == 6 && j == 1 ) || (i == 6 && j == 12 ) || (i == 1 && j == 8 ) || (i == 12 && j == 8 ) || (i == 13 && j == 6 ) || (i == 2 && j == 6 ) ) {
        stop = 1;
      }

      if (board[i][j].length() <= 2){
        cout << board[i][j] << " ";
      }
      else{
        if (stop == 1){
          cout << "S" << duplicate_places +1 << " ";    //If on stop display like S1, else show as 01.
          arr[duplicate_places].x = i;     //arr[0]={[6,1], }
          arr[duplicate_places].y = j;
          stop_or_not[duplicate_places]='S';   //4 duplicates positions, {'S','S', '*', }
          duplicate_places++;
          stop = 0;
        }
        else{
          cout << "*"<<duplicate_places +1 << " ";    //If on stop display like S1, else show as 01.
          arr[duplicate_places].x = i;
          arr[duplicate_places].y = j;
          stop_or_not[duplicate_places] = '*';
          duplicate_places++;
        }
      }
    }
    cout <<endl;
  }
  cout << endl<<endl;
  if (duplicate_places > 0){
    for (int i=0; i<duplicate_places; ++i){      //R1Y1Y2
      cout << stop_or_not[i] << i << " = ";
      //length=board[arr[i].x][arr[i].y].length()/2
      for (int j=0; j< (board[arr[i].x][arr[i].y].length()/2)  ; ++j){
        cout << board[arr[i].x][arr[i].y].substr(2*j,2*j+2) << " ";
      }
      cout << endl;
    }
  }
}

void set_the_board(Player_current_details *players, int num_players, string board[][15]) {
  string token;

  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      if ((j==6|| j==7||j==8||i==6||i==7||i==8) && (j!=i) && (j+i!=14)){
        board[i][j]="XX";
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
    if (i == 0){
      token = "";
      token = token + players[i].token;
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
  }
}

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


bool can_move(string board[][15], int player_number, int dice_roll, int row_index, int col_index){
  bool can_be_moved;
  if((col_index < 6 && (row_index < 6 || row_index > 8)) || \ 
  (col_index > 8 && (row_index < 6 || row_index > 8))){
    if(dice_roll == 6){
      return 1;
    }
    else{
      return 0;
    }
  }
  can_be_moved = ! (col_index == 7 && (row_index == 6 || row_index == 8) || row_index == 7 && (col_index == 6 || col_index == 8));  //has reached home or not
  int col_index2 = col_index, row_index2 = row_index;
  token_movement(player_number, dice_roll, row_index2, col_index2);
  return !(col_index == col_index2 && row_index == row_index2) && \
  can_be_moved; //else return 1
}

string will_kill(string board[][15], int player_number, string token, int dice_roll, int row_index, int col_index){
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

void send_home(string board[][15], int player_killed, string token2){
  if (player_killed == 0){
    if ( token2[1] == 1){
      board[1][1] = token2;
    }
    else if ( token2[1] == 2){
      board[1][3] = token2;
    }
    else if ( token2[1] == 3){
      board[3][1] = token2;
    }
    else {
      board[3][3] = token2;
    }
  }      //for example, if player_killed =0, than its the first player that is being killed

  else if (player_killed == 1){
    if ( token2[1] == 1){
      board[11][11] = token2;
    }
    else if ( token2[1] == 2){
      board[11][13] = token2;
    }
    else if ( token2[1] == 3){
      board[13][11] = token2;
    }
    else {
      board[13][13] = token2;
    }
  }

  else if (player_killed == 2){
    if ( token2[1] == 1){
      board[11][1] = token2;
    }
    else if ( token2[1] == 2){
      board[11][3] = token2;
    }
    else if ( token2[1] == 3){
      board[13][1] = token2;
    }
    else {
      board[13][3] = token2;
    }
  }

  else{
    if ( token2[1] == 1){
      board[1][11] = token2;
    }
    else if ( token2[1] == 2){
      board[1][13] = token2;
    }
    else if ( token2[1] == 3){
      board[3][11] = token2;
    }
    else {
      board[3][13] = token2;
    }
  }
}



void replace_old_position(string board[][15], int row, int column, string token){
  if (board[row][column].length() > 2){   //if double token on previous place, so what will happen to previous location is
    for (int i=0; i< board[row][column].length(); ++i){
      if ( board[row][column][i] == token [0] && board[row][column][i+1] == token[1]){
        board[row][column].erase(i, 2);
        break;
      }

    }

  }
  else { //no double token on one place, so what will happen to previous location is

    if ( (row == 6 && column == 1) || ((row == 1 && column == 8)) || (row == 8 && column == 13) || (row == 13 && column == 6)){
      board[row][column] = "SS";
    }

    else if( row == 7 && ( column == 1 || column == 2 || column == 3 || column == 4 || column == 5)) {
      board[row][column] = "RS";
    }
    else if(row == 7 && ( column == 9 || column == 10 || column == 11 || column == 12 || column == 13)) {
      board[row][column] = "YS";
    }
    else if ( column == 7 && (row == 1 || row == 2 || row == 3 || row == 4 || row == 5)){
      board[row][column] = "GS";
    }
    else if ( column == 7 && (row == 9 || row == 10 || row == 11 || row == 12 || row == 13) ) {
      board[row][column] = "BS";
    }
    else if ( ((row  == 1 && column ==1) || (row ==1 && column ==3) || (row ==1 && column ==11) || (row ==1 && column ==13) || (row ==3 && column ==1) || (row ==3 && column ==3) || (row ==3 && column ==11) || (row ==3 && column ==13) || (row ==11 && column ==1) || (row ==11 && column ==3) || (row ==11 && column ==11) || (row ==11 && column ==13) || (row ==13 && column ==1) || (row ==13 && column ==3) || (row ==13 && column ==11) || (row ==13 && column ==13)) ) {
      board[row][column] = "  ";
    }
    else{
      board[row][column] = "XX";
    }
  }
}

void replace_new_position(Player_current_details *players, int player_number, string board[][15], int row, int column, string token, int  turn_count) {
  // string token2;
  // if (has_won()){
  //   board[row][column] += token;
  //     cout << players.username[turn_count]<< "\'s token has won"
  //   }
  //
  // }
  //else{
  if (board[row][column][1] == '1' || board[row][column][1] == '2' || board[row][column][1] == '3' || board[row][column][1] == '4'){   //if double token on new place which I check by checking 2nd index of it, so what will happen to new location is
    token2 = will_kill(board, player_number, token, int dice_roll, int row_index, int col_index);


    //will send the token back to its respective home
    if (token2.length() == 2) {
      for (int i = 0; i < board[row][column].length(); ++i ){
        if ( board[row][column][i] == token2 [0] && board[row][column][i+1] == token2[1]){
          board[row][column].erase(i, 2);
          for (int i = 0; i < player_number; ++i){
            if (players.token[i] == token2[0]){
              send_home(board, i, token2)   //where i is the player killed, for example, if i=0, than its the first player that is being killed
              cout << " OOPS!!" << players.username[i] << "\'s token has been killed"<<endl;
            }
          }
        }
      }
    }
    else {
      board[row][column] += token;
    } //R1R2Y3Y$
  }

  else{
    board[row][column] = token ;
  }
  //}
}

void make_a_move(Player_current_details *player, int turn_count, int player_number, int No_of_sixes, int dice_number, string board[][15], int &Num_player_won){
  int position [2];
  string token;
  int old_position [2];

  for (int i = 0 ; i < No_of_sixes+1; ++i) {          //three sixes, dice_number=0, No_of_sixes = 2, dice_number=5
    cout <<"which token would you like to move?"<<endl;
    cin >> token;
    int dice_roll = 0;
    if ( i < No_of_sixes){
        dice_roll = 6;
    }
    else{
      dice_roll = dice_number;
    }


    find_where (position, board, token);  //row=6, column =2
    old_position[0] = position[0];
    old_position[1] = position[1];

    if (can_move( board, player_number, dice_roll, position[0], position[1]) ) {

      if (No_of_sixes != 0){
      //if in their bases, then move that token out
      //store new position of the token
      if ((position[0] == 1 && position[1] == 1) || (position[0]==1 && position[1]==3) || (position[0]==1 && position[1]==11) || (position[0]==1 && position[1]==13) || (position[0]==3 && position[1]==1) || (position[0]==3 && position[1]==3) || (position[0]==3 && position[1]==11) || (position[0]==3 && position[1]==13) || (position[0]==11 && position[1]==1) || (position[0]==11 && position[1]==3) || (position[0]==11 && position[1]==11) || (position[0]==11 && position[1]==13) || (position[0]==13 && position[1]==1) || (position[0] == 13 && position[1]==3) || (position[0]==13 && position[1]==11) || (position[0]==13 && position[1]==13)){
        if (turn_count == 0){
          position[0] = 6;
          position[1] = 1;
        }
        else if(turn_count==1){
          position[0] = 8;
          position[1] = 13;
        }
        else if(turn_count == 2){
          position[0] = 13;
          position[1] = 6;
        }
        else if (turn_count == 3){
          position[0] = 1;
          position[1] = 8;
        }
      }

      //if not in bases and your number is six.
      //store new position of the token.

      else {
        token_movement(turn_count+1, 6, position[0], position[1] )   //will return modified in  position array
      }
    }

      else if (No_of_sixes == 0){
      token_movement(turn_count+1, dice_number, position[0], position[1] )
    }
      replace_old_position(board, old_position[0], old_position[1], token);
      replace_new_position(player, player_number, board, position[0], position[1], token, turn_count);
      show_board(board);
      No_of_sixes--;
      if (has_won()){
        Num_player_won += 1;
        player[turn_count].rank = Num_player_won;
        return;
      }

    }

    else{ //ask  about it
      cout << "Your selected token cannot be moved. Please select another token,"<<endl;
      make_a_move(players_current_progress, turn_count, num_player, No_of_sixes, dice_number, board);
      break;
    }
  }
}




int main(){
  int num_players;
  int turn_count=0;   //0 means 1st player
  int dice_number=0;
  int No_of_sixes = 0;
  cout << "Please input number of players: (2, 3 or 4)" << endl;
  string board[15][15];
  cin >> num_players;
  while(num_players > 4){
    cout << "Number of players cannot be greater than 4" << endl;
    cout << "Please input number of players again" << endl;
    cin >> num_players ;
  }
  while(num_players < 2){
    cout << "Number of players cannot be less than 2" << endl;
    cout << "Please input number of players again" << endl;
    cin >> num_players;
  }

  string username, chosen_tokens = "";
  Player_current_details * players_current_progress = new Player_current_details [num_players];
  Profile * players_profile = new Profile [num_players];
  for(int i = 0; i < num_players; i++){
    cout << "Player " << i << ":" << endl;
    username = enter_username();
    players_current_progress[i].player_number = i + 1;
    players_current_progress[i].username = username;
    load_profile(players_profile[i], username);
    players_current_progress[i].token = select_token(players_profile[i].token_symbols, chosen_tokens, chosen_tokens.length());
    chosen_tokens = chosen_tokens + players_current_progress[i].token;
  }


  show_board(board);
  set_the_board(players_current_progress, num_players, board);

  //printing the board
  //-------------------------------------------------------------------------
  int Num_player_won = 0;
  while (Num_player_won < num_players-1){
    if (turn_count == player_number){
      turn_count = 0;
    }
    cout << player[turn_count].username<< "'s turn" << endl;
    dice_number = roll_dice(player, turn_count, No_of_sixes, dice_number);
    if (dice_number != 0){
      cout << dice_number<< endl;
      make_a_move(players_current_progress, turn_count, num_player, No_of_sixes, dice_number, board, Num_player_won);
    }
    No_of_sixes=0;
    dice_number=0;
    turn_count++;
  }

  players_current_progress[num_players - 1].rank = num_players -1;


}
