#include <iostream>
#include <string>
using namespace std;

void check_duplicates(string board[][15], int starting_pos[], int pos_found[]){
  int j;
  for(int i = starting_pos[0]; i < 15; i++){
    if(i == starting_pos[0]){
      j = starting_pos[1];
    }
    else{
      j = 0;
    }
    for(j; j < 15; j++){
      if(board[i][j].length() > 2){
        pos_found[0] = i;
        pos_found[1] = j;
        return;
      }
    }
  }
  pos_found[0] = -1;
  pos_found[1] = -1;
  return;
}

int main(){
  string board[15][15];
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      board[i][j] = "AB";
    }
  }
  board[10][10] = "ABC";
  board[0][14] = "ABABABBABABA";
  int pos_found[2], starting_pos[2];
  starting_pos[0] = 0;
  starting_pos[1] = 0;
  check_duplicates(board, starting_pos, pos_found);
  while(pos_found[0] != -1){
    cout << "i: " << pos_found[0] << " j: " << pos_found[1] << endl;
    starting_pos[0] = pos_found[0];
    starting_pos[1] = pos_found[1] + 1;
    check_duplicates(board, starting_pos, pos_found);
  }
  return 0;
}
