
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;


struct cordinates{
  int x;
  int y;
};

void show_board(string board[][15]){
  int duplicate_places = 0;
  int stop = 0;
  char stop_or_not[8];
  cordinates arr[8];

  for (int i=0; i<15; ++i){
    for (int j=0; j<15; ++j){
      //write a condition to see if on stop
      if (board[i][j].length() <= 2){
        cout << board[i][j] << " ";
      }
      else{
        if (stop == 1){
          cout << "S" << duplicate_places +1 << " ";    //If on stop display like S1, else show as 01.
          arr[duplicate_places].x = i;
          arr[duplicate_places].y = j;
          stop_or_not[duplicate_places]='S';
          duplicate_places++;
        }
        else{
          cout << "*"<<duplicate_places +1 << " ";    //If on stop display like S1, else show as 01.
          arr[duplicate_places].x = i;
          arr[duplicate_places].y = j;
          stop_or_not[duplicate_places]='*';
          duplicate_places++;
        }
      }
    }
    cout <<endl;
  }
  cout << endl<<endl;
  if (duplicate_places > 0){
    for (int i=0; i<duplicate_places; ++i){      //R1Y1Y2
      cout << stop_or_not[i] << i << " = ";
      //length=board[arr[i].x][arr[i].y].length()/2
      for (int j=0; j< (board[arr[i].x][arr[i].y].length()/2)  ; ++j){
        cout << board[arr[i].x][arr[i].y].substr(2*j,2*j+2) << " ";
      }
      cout << endl;
    }
  }
}
