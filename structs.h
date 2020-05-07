//structs.h
#include <iostream>
#include <string>
using namespace std;
#ifndef STRUCTS_H
#define STRUCTS_H

//Represents the profile of a single user
struct Profile{
  string username;
  int level;
  int xp;
  string token_symbols; //depends on XP
  int played; //matches played
  int won; //matches won
  string win_percentage;
};
//Represents current details of a single player (during a game)
struct Player_current_details{
  string username;
  char token; //token during the match
  int player_number;
  int rank;
};

#endif
