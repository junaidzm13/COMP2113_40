#include <iostream>
#include <string>
#include "select_token.h"
using namespace std;

/*This function is a helper function to select_token and takes same parameters
as select_token and an integer representing the size of chosen_tokens. It returns
a string containing all the tokens availabale to the user.*/
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

/*This function takes two strings, one representing the available tokens to
the user depending on user's XP and other representing the already chosen
tokens by other players. This function prompts the user to choose tokens from
the displayed list of available tokens. Returns the chosen token as a character.*/
char select_token(string user_tokens, string chosen_tokens){
  int size = chosen_tokens.length();
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
