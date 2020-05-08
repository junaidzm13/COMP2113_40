#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "read_username.h"
#include "structs.h"
using namespace std;

/*This function takes a string username representing a new username, and creates a text
file <username>.txt representing the profile of the user and writes this username to usernames.txt.*/
void create_new(string username){
  string filename = username + ".txt";
  ofstream fout;
  fout.open(filename.c_str());
  fout << username << endl;
  fout << 1 << endl; //level
  fout << 0 << endl; //XP
  fout << "YGRB" << endl; //default symbols
  fout << 0 << endl; //matches played
  fout << 0 << endl; //matches won
  fout << "0%" << endl; //winning percentage
  fout.close();
  fout.open("usernames.txt", ios::app);
  fout << username << endl;
  fout.close();
}

/*This function takes a string username, a pointer to array of Player_current_details players 
and an integer i representing one less player number, and returns a boolean whether such
a username exists in the file usernames.txt or not.*/
bool read_username(string username, Player_current_details *players, int i){
  string word;
  int isvalid = 0;
  ifstream fin;
  fin.open("usernames.txt");
  while(fin >> word){
    if(word == username){
      isvalid = 1;
    }
  }
  if(isvalid == 1){
    for(int j = 0; j < i; j++){
      if(username == players[j].username){
        isvalid = 0;
      }
    }
  }
  fin.close();
  return isvalid;
}

/*This function takes two parameters, a pointer to an array of Player_current_details and an 
integer i representing player number less one. Prompts the user to enter his/her username. Calls
read_username to check whether such a username exists and has not been taken already. If it does,
returns that username and if it does not, creates a new file <username>.txt and returns the 
new username entered.*/
string enter_username(Player_current_details *players, int i){
  char createnew;
  string username;
  cout << "Please enter your username: ";
  cin >> username;
  while(read_username(username, players, i) != 1){
    cout << "Invalid username.\nDo you want to create a new profile? (Y/N)" << endl;
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
  cout << "Welcome back " << username << "! Loading your profile. :)" << endl;
  return username;
}
