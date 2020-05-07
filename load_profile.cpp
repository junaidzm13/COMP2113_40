#include <iostream>
#include <string>
#include <fstream>
#include "load_profile.h"
#include "structs.h"
using namespace std;

/*This function takes a Profile user as pass by reference and a string
representing user's username. This function reads the corresponding file of the
 user and populates the corresponding structure accordingly.*/
void load_profile(Profile &user, string username){
  int level, xp, played, won; //played = matches played, won = matches won
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
