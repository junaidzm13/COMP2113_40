#include <iostream>
#include <string>
#include "set_the_board.h"
#include "structs.h"
using namespace std;

/*This function takes a 15x15 2D string array board, a dynamic array of structure
Player_current_details players and an integer representing the number of players.
It populates the array with the required strings that immitates a ludo board.*/
void set_the_board(Player_current_details players[], int num_players, string board[][15]){
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      if ((j==6|| j==7||j==8||i==6||i==7||i==8) && (j!=i) && (j+i!=14)){
        board[i][j]="xx";
      }
      else{
        board[i][j]="  ";
      }
    }
  }
  //In case number of players < 4
  board[11][1]="31";
  board[11][3]="32";
  board[13][1]="33";
  board[13][3]="34";
  board[13][7]="3S";
  board[12][7]="3S";
  board[11][7]="3S";
  board[10][7]="3S";
  board[9][7]="3S";
  board[8][7]="3H";

  board[1][11]="41";
  board[1][13]="42";
  board[3][11]="43";
  board[3][13]="44";
  board[1][7]="4S";
  board[2][7]="4S";
  board[3][7]="4S";
  board[4][7]="4S";
  board[5][7]="4S";
  board[6][7]="4H";

  for (int i = 0; i < num_players; ++i){
    string token = "";
    if (i == 0){
      token = token + players[i].token;
      board[1][1]=token+"1";
      board[1][3]=token+"2";
      board[3][1]=token+"3";
      board[3][3]=token+"4";
      board[7][1]=token+"S";
      board[7][2]=token+"S";
      board[7][3]=token+"S";
      board[7][4]=token+"S";
      board[7][5]=token+"S";
      board[7][6]=token+"H";
    }
    else if (i == 1){
      token = "";
      token = token + players[i].token;
      board[11][11]=token+"1";
      board[11][13]=token+"2";
      board[13][11]=token+"3";
      board[13][13]=token+"4";
      board[7][13]=token+"S";
      board[7][12]=token+"S";
      board[7][11]=token+"S";
      board[7][10]=token+"S";
      board[7][9]=token+"S";
      board[7][8]=token+"H";
    }
    else if(i == 2){
      token = "";
      token = token + players[i].token;
      board[11][1]=token+"1";
      board[11][3]=token+"2";
      board[13][1]=token+"3";
      board[13][3]=token+"4";
      board[13][7]=token+"S";
      board[12][7]=token+"S";
      board[11][7]=token+"S";
      board[10][7]=token+"S";
      board[9][7]=token+"S";
      board[8][7]=token+"H";
    }
    else{
      token = "";
      token = token + players[i].token;
      board[1][11]=token+"1";
      board[1][13]=token+"2";
      board[3][11]=token+"3";
      board[3][13]=token+"4";
      board[1][7]=token+"S";
      board[2][7]=token+"S";
      board[3][7]=token+"S";
      board[4][7]=token+"S";
      board[5][7]=token+"S";
      board[6][7]=token+"H";
    }
    board[8][2]="SS";
    board[8][13]="SS";
    board[6][1]="SS";
    board[6][12]="SS";
    board[1][8]="SS";
    board[12][8]="SS";
    board[13][6]="SS";
    board[2][6]="SS";
  }
}
