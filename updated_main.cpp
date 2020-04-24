#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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
  char token;
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
    username = enter_username();
    players_current_progress[i].player_number = i + 1;
    load_profile(players_profile[i], username);
    players_current_progress[i].token = select_token(players_profile[i].token_symbols, \
      chosen_tokens, chosen_tokens.length());
    chosen_tokens = chosen_tokens + players_current_progress[i].token;
  }
  cout << chosen_tokens << endl;

  //Testing
  /*char x = select_token("YGRB#", "YB", 2);
  cout << x << endl;
  */
  delete [] players_current_progress;
  delete [] players_profile;
  return 0;
}
