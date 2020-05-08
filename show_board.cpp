#include <iostream>
#include <string>
#include <iomanip>
#include "show_board.h"
#include "structs.h"
using namespace std;

//represents positions in a 2-D array
struct cordinates{
  int x; //row index
  int y; //col index
};

/*This function takes a 2-D string array board representing a board, a pointer pointing to the dynamic
array players containing structure Player_current_details and an integer num_players representing the number of
players as parameters and will show the board as an output to the screen.*/
void show_board(string board[][15], Player_current_details *players, int num_players){
  cout << endl << setfill('-') << setw(45) << "" <<endl;
  int duplicate_places = 0;
  int stop = 0;
  char stop_or_not[8];
  cordinates arr[8]; //
  for (int i = 0; i < 15; ++i){
    for (int j = 0; j < 15; ++j){
      //-----------------------------------------------------------------------
      //Always have token_symbol + H at home positions.
      if(i == 7 && j == 6){
        cout << players[0].token << 'H' << " ";
        continue;
      }
      else if(i == 7 && j == 8){
        cout << players[1].token << 'H' << " ";
        continue;
      }
      else if(i == 8 && j == 7 && num_players >= 3){
        cout << players[2].token << 'H' << " ";
        continue;
      }
      else if(i == 6 && j == 7 && num_players == 4){
        cout << players[3].token << 'H' << " ";
        continue;
      }
      //-----------------------------------------------------------------------
      if ( (i == 8 && j == 2) || (i == 8 && j == 13 ) || (i == 6 && j == 1 ) || (i == 6 && j == 12 ) || (i == 1 && j == 8 ) || (i == 12 && j == 8 ) || (i == 13 && j == 6 ) || (i == 2 && j == 6 ) ) {
        stop = 1;
      }
      else{
        stop = 0;
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
  //---------------------------------------------------------------------------
  //Outputs the status of each player at his home position i.e. which tokens have successfully reached home.
  string homeOutput = "", home_symbol = "H";
  for(int playerNum = 0; playerNum < num_players; playerNum++){
    homeOutput = homeOutput + players[playerNum].token + "H" + " = {";
    home_symbol = players[playerNum].token + home_symbol;
    int row = 7 + (playerNum == 2) - (playerNum == 3);
    int col = 6 + (playerNum >= 1) + (playerNum == 1);
    if(board[row][col].substr(0, 2) != home_symbol){
      homeOutput = homeOutput + board[row][col].substr(0, 2);
      for(int j = 1; j < board[row][col].length() / 2; j++){
        homeOutput = homeOutput + " " + board[row][col].substr(2*j, 2);
      }
    }
    homeOutput = homeOutput + "}";
    if(playerNum == 2){
      cout << endl;
    }
    cout << setfill(' ') << left << setw(20) << homeOutput;
    homeOutput = "";
    home_symbol = "H";
  }
  cout << endl;
  //---------------------------------------------------------------------------
  if (duplicate_places > 0){
    for (int i=0; i<duplicate_places; ++i){  //R1Y1Y2
      cout << stop_or_not[i] << i +1 << " = ";
      for (int j=0; j< (board[arr[i].x][arr[i].y].length()/2)  ; ++j){
        cout << board[arr[i].x][arr[i].y].substr(2*j,2) << " ";  //Y1Y2Y3
      }

      cout << endl;
    }
  }
  cout << setfill('-') << setw(45) << "" << endl << endl;
}
