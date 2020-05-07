#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "update_profile.h"
#include "structs.h"
using namespace std;

//This function takes two integers, rank representing the rank of the player and num_players
//representing the number of players and returns an integer representing xp gained.
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

//This function takes an integer level representing the level and returns a string
//representing the token unlocked on that particular level. Only called when levelled up.
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

/*This function takes Profile structure user representing a profile of a user as pass-by-reference
and two integers, one representing the number of players and the other the rank obtained
by the user. This function updates the user's text file and updates the structure as well.*/
void update_profile(Profile &user, int num_players, int rank){
  int newxp, newlevel, matches_played, matches_won, havewon, rank_counter;
  double win_percent, won, played;
  ofstream fout;
  string filename = user.username + ".txt";
  fout.open(filename.c_str());
  fout << user.username << endl;
  newxp = user.xp + getxp(rank, num_players);
  user.xp = newxp;
  newlevel = newxp / 10 + 1;
  if(newlevel > user.level){
    cout << "Congratulations! " << user.username << " leveled up to " << newlevel << "!" << endl;
    if(newlevel <= 10){
      cout << "You have unlocked a new token symbol '" << tokens_unlock(newlevel) << "'!" << endl;
      user.token_symbols += tokens_unlock(newlevel);
    }
    user.level = newlevel;
    cout << endl;
  }
  fout << newlevel << endl;
  fout << newxp << endl;
  fout << user.token_symbols << endl;
  user.played += 1;
  fout << user.played << endl;
  rank_counter = num_players + 1 - rank; //inverting the rank 1 = 4, 2 = 3 and so on.
  havewon = (rank_counter > num_players / 2); //won if rank > num_players / 2
  user.won = user.won + havewon;
  fout << user.won << endl;
  won = user.won;
  played = user.played;
  win_percent = won / played * 100;
  fout << fixed << setprecision(2);
  fout << win_percent << "%" << endl;
  fout.close();
  return;
}
