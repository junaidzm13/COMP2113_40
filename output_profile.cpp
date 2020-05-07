#include <iostream>
#include <string>
#include <iomanip>
#include "structs.h"
using namespace std;

/*This function takes a user's profile user as Profile and outputs
to the screen the whole profile of the user with Profile user.*/
void output_profile(Profile user){
  double mPlayed = user.played, mWon = user.won;
  cout << "Username: " << user.username << endl;
  cout << setfill(' ') << left << setw(7) << "Level: " << setw(5) << user.level;
  cout << left << setw(4) << "XP: " << setw(4) << user.xp << endl;
  cout << "Avaialable Tokens: " << user.token_symbols << endl;
  cout << "Matches Played: " << user.played << endl;
  cout << "Matches Won: " << user.won << endl;
  cout << fixed << setprecision(2);
  cout << "Winning Percentage: " << mWon / mPlayed * 100 << "%" << endl;
}
