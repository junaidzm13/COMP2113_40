#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "read_username.h"
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

/*This function takes a string username and returns a boolean whether such
a username exists in the file usernames.txt or not.*/
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

/*This function takes no parameters. Prompts the user to enter his/her username. Calls
read_username to check whether such a username exists. If it does, returns that username
and if it does not, creates a new file <username>.txt and returns the new username entered.*/
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
  cout << "Welcome back " << username << "! Loading your profile. :)" << endl;
  return username;
}
