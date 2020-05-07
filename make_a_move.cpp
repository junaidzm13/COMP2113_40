#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cmath>
#include <vector>
#include <cctype>
#include "make_a_move.h"
#include "show_board.h"
#include "structs.h"
using namespace std;

//Structure representing the position on a 15x15 2-D array
struct cordinates{
  int x; //row_index
  int y; //col_index
};

/*Given integers player_number, dice_roll (singular), and a token's col and row indices as indexes
this function tells you at what position (col and row indices) this token will be at after
the move. Changes the values of row_index and col_index (as passed-by-reference)*/
void token_movement(int player_number, int dice_roll, int &row_index, int &col_index){
  int move1, move2, move3; //represent the number of moves in different directions with a single dice roll
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
    else if(col_index > 8 && row_index == 6){//near player 2's home
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
    if(row_index < 6 && col_index == 8){ //near player4's home
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
    else if(row_index > 8 && col_index == 8){ //near player 3's home
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

//converts int i to character type
char itoc(int i){
  char c;
  c = i + 48;
  return c;
}
//converts digit char c to type int
int ctoi(char c){
  int i;
  i = c - 48;
  return i;
}

/*Takes a string and repeatedly prompts the user to enter a single digit.
Returns that digit converted to int type.*/
int check_digit(string num){
  while (num.length() != 1 || !isdigit(num[0])){
    cout << "Warning! Please select a single integer! ";
    cin >> num;
  }
  return ctoi(num[0]);
}

/*This function takes 4 parameters, a 2-D 15x15 string array representing the board, 2 integers,
player_number and the dice_roll and 4th a string representing the chosen token. This function
returns a boolean checking whether the particular token can move or not.*/
bool can_move(string board[][15], int player_number, int dice_roll, string token){
  bool can_be_moved;
  int position[2];
  linear_search(position, board, token);
  if((position[1] < 6 && (position[0] < 6 || position[0] > 8)) || \
  (position[1] > 8 && (position[0] < 6 || position[0] > 8))){ //checks whether at base
    if(dice_roll == 6){
      return 1;
    }
    else{
      return 0;
    }
  }
  can_be_moved = ! (position[1] == 7 && (position[0] == 6 || position[0] == 8) || \
  position[0] == 7 && (position[1] == 6 || position[1] == 8)); //at home or not
  int col_index2 = position[1], row_index2 = position[0];
  token_movement(player_number, dice_roll, row_index2, col_index2); //moves or not
  return !(position[1] == col_index2 && position[0] == row_index2) && \
  can_be_moved; //else return 1
}

/*This function takes 5 parameters, a 2-D 15x15 string array board representing the board, 3
integers, one player_number representing the player number and the other two row_index, col_index
representing the new row and column indices of the token respectively and 5th a string
representing the chosen token. This function checks whether this token kills another token,
if it does this token will return the string containing the token being killed. If
 no token is being killed, this function will return an empty string.*/
string will_kill(string board[][15], int player_number, string token, int row_index, int col_index){
    bool land_at_home, land_at_star, not_on_empty, not_on_own_token, kills;
    land_at_star = ((col_index == 1 || col_index == 12) && row_index == 6 || \
      (col_index == 2 || col_index == 13) && row_index == 8 || \
      col_index == 6 && (row_index == 2 || row_index == 13) || \
      col_index == 8 && (row_index == 1 || row_index == 12));
    if(player_number == 1){
      land_at_home = (row_index == 7 && col_index > 0 && col_index <= 6);
    }
    else if(player_number == 4){
      land_at_home = (col_index == 7 && row_index > 0 && row_index <= 6);
    }
    else if(player_number == 2){
      land_at_home = (row_index == 7 && col_index >= 8 && col_index < 14);
    }
    else{
      land_at_home = (col_index == 7 && row_index >= 8 && row_index < 14);
    }
    not_on_empty = (board[row_index][col_index] != "xx" && board[row_index][col_index].length() == 2);
    not_on_own_token = board[row_index][col_index][0] != token[0];

    kills = (! land_at_star && ! land_at_home && not_on_empty && not_on_own_token);
    if(board[row_index][col_index].length() > 2){ //more than one token, cannot kill
      kills = 0;
    }
    if(kills == 1){
      return board[row_index][col_index];
    }
    else{
      return "";
    }
}

/*This function searches the board to find the target's row and column indices.
If found updates the array position else make elements equal -1. position[0] = row index
position[1] = column index*/
void linear_search(int position[], string board [][15], string token ){
  string word;
  for (int i = 0; i < 15; ++i){
    for (int j = 0; j < 15;++j){
      word = board[i][j];
      if (word.length() <= 2){
        if (word[0] == token[0] && word[1] == token[1]) {
          position[0] = i;
          position[1] = j;
          return;
        }
      }
      else{
        for (int k = 0; k < word.length()/2; ++k){
          if (word.substr(2*k,2) == token) {
            position[0] = i;
            position[1] = j;
            return;
          }
        }
      }
    }
  }
  position[0]=-1;
  position[1]=-1;
}

/*This function takes two arguments an integer vector allDiceRolls and an integer selected_dice.
This function searches the vector and returns the first index where selected_dice is found.
Otherwise, returns -1.*/
int searchVector(vector<int> allDiceRolls, int selected_dice){
    for (int i = 0; i < allDiceRolls.size(); ++i){
      if (allDiceRolls[i] == selected_dice){
        return i;
      }
    }
    return -1;
}

//This function prints a integer vector allDiceRolls containing all the dice rolls in a prescribed fashion.
void printVector(vector <int> allDiceRolls){
  int size = allDiceRolls.size();
  if(size != 0){
    cout << "{" << allDiceRolls[0];
    for (int i = 1 ; i < size; i++){
      cout  << ", " << allDiceRolls[i];
    }
    cout << "} ";
  }
}

/*This function takes an integer vector v (passed-by-reference), and two integers one
representing total number of dice rolls Num_of_rolls and the other representing
the value of the dice roll that's not equal to 6, dice_number. This function
populates the vector with the all the obtained dice rolls at a single turn.*/
void populateVector(vector <int> &v, int Num_of_rolls, int dice_number){
  int num_sixes = Num_of_rolls - 1;
  for (int i = 0; i < Num_of_rolls; ++i){
    if (num_sixes > 0){
      v[i] = 6;
      num_sixes -= 1;
    }
    else{
      v[i] = dice_number;
    }
  }
}

/*This function takes a dynamic array player which contains the details of current players that are playing,
four integers, and a 2D array. The first integer turn_count represents which player's turn  it is. The second
integer num_players represent the total number of players who are playing the game. The third integer
No_of_sixes represent the number if sixes a player got (can only be 0,1,2). The fourth integer dice_number
represents the number which a player got on the last roll of a die in his turn which can only be 1,2,3,4,5
here. The 2D array named board stores the details of token positions.
The purpose of this function is to allow a player to move his token depending on the result from roll_dice function.
The selected token by the player will be moved and after every single move, a board will be printed to show
the movement of his selected token.*/
void make_a_move(Player_current_details *player, int turn_count, int num_players, int No_of_sixes, int dice_number, string board[][15]){
  int position [2];  //to store the new position of the selected token
  string token;
  int dice_roll = 0;   //to store the number on dice that player will move
  string dice_rollStr;     //stores the dice_roll as string so that game does not crash if players input anything other than integer
  int old_position [2];     //to store the old position on board from which the selected token move to new position.
  int Num_of_rolls = No_of_sixes +1;    //stores the total number of dice rolls.
  vector<int> allDiceRolls (Num_of_rolls);   //vector containing all the dice rolls results
  populateVector(allDiceRolls, Num_of_rolls, dice_number);
  vector<int> allDiceRolls_copy;

  for (int i = 0 ; i < Num_of_rolls; ++i) {
    bool check_all; //check_true checks whether any of the tokens can move the given dice roll
    string checking; // contains the token to be checked whetherit can be moved or not
    int vec_index;
    int sizeDices_2; //copy of allDiceRolls and eventually contains only the dice rolls that can be moved
    allDiceRolls_copy = allDiceRolls;
    sizeDices_2 = allDiceRolls_copy.size();
    for(vec_index = sizeDices_2 - 1; vec_index >= 0; vec_index--){
      check_all = false;
      checking = "";
      checking = player[turn_count].token;
      for (int i = 1; i < 5; ++i){
        checking += itoc(i);
        if (can_move(board, turn_count + 1, allDiceRolls_copy[vec_index], checking)){  //a condition to check if there exist a valid move with given all the dice numbers.
          check_all = true;
        }
        checking = player[turn_count].token;
      }
      if(check_all == false){
        allDiceRolls_copy.erase(allDiceRolls_copy.begin() + vec_index);
      }
    }
    sizeDices_2 = allDiceRolls_copy.size();
    if (sizeDices_2 == 0){
      cout << "You cannot move any token! Turn passed." << endl;
      show_board(board, player, num_players);
      break;
    }
    else if(sizeDices_2 == 1){
      dice_roll = allDiceRolls_copy[0];
    }
    else{
      cout << "Which dice roll would you like to move first: " << endl;
      printVector(allDiceRolls_copy);
      cin >> dice_rollStr;
      dice_roll = check_digit(dice_rollStr);

      vec_index = searchVector(allDiceRolls_copy, dice_roll);
      while (vec_index == -1){
        cout << "Selected dice roll does not exist! Please select again ";
        printVector(allDiceRolls_copy);
        cin >> dice_rollStr;
        dice_roll = check_digit(dice_rollStr);
        vec_index = searchVector(allDiceRolls_copy, dice_roll);
      }
    }
    string possible_tokens = "";
    checking = player[turn_count].token;
    for (int i = 1; i < 5; ++i){
      checking += itoc(i);
      if (can_move(board, turn_count + 1, dice_roll, checking)){
        possible_tokens += checking;
      }
      checking = player[turn_count].token;
    }

    bool correct_token = false;
    cout << "Dice roll = " << dice_roll << "\nWhich token would you like to move? ";
    cin >> token;
    while (correct_token == false){
      for (int i =0 ; i < possible_tokens.length() / 2; ++i){
        if (token == possible_tokens.substr(2 * i, 2)){
          correct_token = true;
        }
      }
      if(correct_token == false){
        cout << "Either the token you entered is invalid or it cannot be moved." << endl;
        cout << "Please select again. ";
        cin >> token;
      }
    }
    linear_search (position, board, token);  //to find the existing position of the selected token.
    old_position[0] = position[0];
    old_position[1] = position[1];

    if (dice_roll == 6){

      //if the token is in the bases and the selected dice number is six then it will move the token out of the bases.
      if ((position[0] == 1 && position[1] == 1) || (position[0]==1 && position[1]==3) || (position[0]==1 && position[1]==11) || (position[0]==1 && position[1]==13) || (position[0]==3 && position[1]==1) || (position[0]==3 && position[1]==3) || (position[0]==3 && position[1]==11) || (position[0]==3 && position[1]==13) || (position[0]==11 && position[1]==1) || (position[0]==11 && position[1]==3) || (position[0]==11 && position[1]==11) || (position[0]==11 && position[1]==13) || (position[0]==13 && position[1]==1) || (position[0] == 13 && position[1]==3) || (position[0]==13 && position[1]==11) || (position[0]==13 && position[1]==13)){
        if (turn_count == 0){
          position[0] = 6;
          position[1] = 1;
        }
        else if(turn_count == 1){
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

      //if not in bases and the selected dice number is six then it store new position of the token.
      else {
        token_movement(turn_count + 1, dice_roll, position[0], position[1]);   //will change new position in array named position
      }
    }

    //if the dice number a player has to move is not six, then it will move the selected token (which is outside the bases).
    else{
      token_movement(turn_count + 1, dice_number, position[0], position[1] );
    }
    replace_old_position(player, board, old_position[0], old_position[1], token, turn_count);
    replace_new_position(player, num_players, board, position[0], position[1], token, turn_count);
    show_board(board, player, num_players);
    vec_index = searchVector(allDiceRolls, dice_roll);
    allDiceRolls.erase(allDiceRolls.begin() + vec_index);
  }
}

/*This function takes a dynamic array player which contains the details of current players that are playing,
three integers, one string, and a 2D array. The 2D array named board stores the details of token positions.
The string token represents the token selected by the player to move. The integer row and the integer column
represtents the position on the board. This position represents the position from which the selected token move
to another new postion on board. The third integer turn_count represents which player's turn  it is.
After the player selects a valid token to move, this function will change the last position of token on board as
it shouls be.*/
void replace_old_position(Player_current_details *players, string board[][15], int row, int column, string token, int turn_count){
  if (board[row][column].length() > 2){   //if more than one token on previous place, so what will happen to previous location is
    for (int i = 0; i< board[row][column].length()/2; ++i){
      if ( board[row][column].substr(2*i,2) == token){
        board[row][column].erase(2*i, 2);
        return;
      }
    }
  }
  else { //only one token on one place, so what will happen to previous location is

    if ( (row == 6 && column == 1) || ((row == 1 && column == 8)) || (row == 8 && column == 13) || (row == 13 && column == 6) \
  || (row == 8 && column == 2) || (row == 6 && column == 12) || (row == 12 && column == 8) || (row == 2 && column == 6)){
      board[row][column] = "SS";
    }
    else if ( (row == 7 && ( column >= 1 && column <= 13) ) || \
       ( column == 7 && (row >= 1 && row <= 13) ) ){
          string s = "S";
          board[row][column] = players[turn_count].token + s;
        }

    else if ( ((row  == 1 && column ==1) || (row ==1 && column ==3) || (row ==1 && column ==11) || (row ==1 && column ==13) || (row ==3 && column ==1) || (row ==3 && column ==3) || (row ==3 && column ==11) || (row ==3 && column ==13) || (row ==11 && column ==1) || (row ==11 && column ==3) || (row ==11 && column ==11) || (row ==11 && column ==13) || (row ==13 && column ==1) || (row ==13 && column ==3) || (row ==13 && column ==11) || (row ==13 && column ==13)) ) {
      board[row][column] = "  ";
    }
    else{
      board[row][column] = "xx";
    }
  }
}

/*This function takes a dynamic array player which contains the details of current players that are playing,
four integers, one string, and a 2D array. The 2D array named board stores the details of token positions.
The string token represents the token selected by the player to move. The first integer player_number represent
the total number of players who are playing the game. The integer row and the integer column represtents
the position on the board. This position represents the new postion where the player's selected
token will move on the board. The fourth integer turn_count represents which player's turn it is.
After the player selects a valid token to move, this function will change the new position of token on board as
it should be.*/
void replace_new_position(Player_current_details *players, int player_number, string board[][15], int row, int column, string token, int  turn_count) {
   string token2;  //to store the token that is killed.

   //If there is/are token previously on new position.
  if (board[row][column][1] == '1' || board[row][column][1] == '2' || board[row][column][1] == '3' || board[row][column][1] == '4'){   //if double token on new place which I check by checking 2nd index of it, so what will happen to new location is
    token2 = will_kill(board, player_number, token, row, column);


    //will send the token2 back to its respective bases
    if (token2.length() == 2) {
      for (int i = 0; i < board[row][column].length(); ++i ){
        if ( board[row][column].substr(i,2) == token2){
          board[row][column] = token;
          for (int i = 0; i < player_number; ++i){
            if (players[i].token == token2[0]){
              send_base(board, i, token2);   //where i is the player killed, for example, if i=0, than its the first player that is being killed
              cout << " OOPS!! " << players[i].username << "\'s token has been killed"<<endl;
            }
          }
        }
      }
    }

    //no token is being killed
    else {
      board[row][column] += token;
    }
  }

  else{ //if no token is previously on new position
    board[row][column] = token;
  }
}

/* This function takes a 2D string array, one string and one integer.  The 2D array named board stores the details
of token positions. The integer player_killed represents which player is being killed. The string token2
represents the token that is being killed.
This function will modify the board by sending back the killed token(token2) to its respective base. It means
token2 will now be stored in the respective players base.*/
void send_base(string board[][15], int player_killed, string token2){
  if (player_killed == 0){
    if ( token2[1] == '1'){
      board[1][1] = token2;
    }
    else if ( token2[1] == '2'){
      board[1][3] = token2;
    }
    else if ( token2[1] == '3'){
      board[3][1] = token2;
    }
    else {
      board[3][3] = token2;
    }
  }      //for example, if player_killed =0, than its the first player that is being killed

  else if (player_killed == 1){
    if ( token2[1] == '1'){
      board[11][11] = token2;
    }
    else if ( token2[1] == '2'){
      board[11][13] = token2;
    }
    else if ( token2[1] == '3'){
      board[13][11] = token2;
    }
    else {
      board[13][13] = token2;
    }
  }

  else if (player_killed == 2){
    if ( token2[1] == '1'){
      board[11][1] = token2;
    }
    else if ( token2[1] == '2'){
      board[11][3] = token2;
    }
    else if ( token2[1] == '3'){
      board[13][1] = token2;
    }
    else {
      board[13][3] = token2;
    }
  }

  else{
    if ( token2[1] == '1'){
      board[1][11] = token2;
    }
    else if ( token2[1] == '2'){
      board[1][13] = token2;
    }
    else if ( token2[1] == '3'){
      board[3][11] = token2;
    }
    else {
      board[3][13] = token2;
    }
  }
}
