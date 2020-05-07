
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;
// struct player_detail{
//   string player_name;
//   string token[4];
// }
struct Profile{
  string username;
  int level;
  int xp;
  string token_symbols;
  int played;
  int won;
  string win_percentage;
};
struct current_traits{
  char token;
  int player_position;
  string status;
  int rank;
};
void show_board(string board[][15]){
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      cout << board[i][j]<<" ";
    }
    cout <<endl;
  }
  cout<<endl<<endl;
}
void set_the_board(string **player_name, int player_number, string board[][15]){
  string Color;
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      if ((j==6|| j==7||j==8||i==6||i==7||i==8) && (j!=i) && (j+i!=14)){
        board[i][j]="XX";
      }
      else{
        board[i][j]="  ";
      }
    }
  }
  for (int i=0; i<player_number; ++i){
    if (i==0){
      Color='R';
    }
    else if (i==1){
      Color='Y';
    }
    else if (i==2){
      Color='B';
    }else {
      Color='G';
    }
    player_name[i][1]=Color + "1";
    player_name[i][2]=Color + "2";
    player_name[i][3]=Color + "3";
    player_name[i][4]=Color + "4";
    if (player_number == 2){
      cout << player_name[i][0]<<" is Red(R)"<<endl;
      cout << player_name[i][0]<<" is Yellow(Y)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[11][11]="Y1";
      board[11][13]="Y2";
      board[13][11]="Y3";
      board[13][13]="Y4";

    }
    else if (player_number == 3){
      cout << player_name[i][0]<<" is Red(R)"<<endl;
      cout << player_name[i][0]<<" is Yellow(Y)"<<endl;
      cout << player_name[i][0]<<" is Blue(B)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[11][11]="Y1";
      board[11][13]="Y2";
      board[13][11]="Y3";
      board[33][13]="Y4";
      board[11][1]="B1";
      board[11][3]="B2";
      board[13][1]="B3";
      board[13][3]="B4";
    }
    else{
      cout << player_name[i][0]<<" is Red(R)"<<endl;
      cout << player_name[i][0]<<" is Yellow(Y)"<<endl;
      cout << player_name[i][0]<<" is Blue(B)"<<endl;
      cout << player_name[i][0]<<" is Green(G)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[11][11]="Y1";
      board[11][13]="Y2";
      board[13][11]="Y3";
      board[13][13]="Y4";
      board[11][1]="B1";
      board[11][3]="B2";
      board[13][1]="B3";
      board[13][3]="B4";
      board[1][11]="G1";
      board[1][13]="G2";
      board[3][11]="G3";
      board[3][13]="G4";
    }
    show_board(board);
  }
}
int roll_dice(string **player_name, int &turn_count, int & No_of_sixes, int &dice_number ){
  cout <<"Rolling the dice!"<<endl;
  srand(time(NULL));
  dice_number = rand()%6+1;
  if (dice_number == 6){
    cout << "6"<<endl<<endl;
    No_of_sixes++;
    if (No_of_sixes < 3){
      roll_dice(player_name, turn_count, No_of_sixes, dice_number);
    }
    if (No_of_sixes==3){
      cout<< player_name[turn_count][0] << " lost his turn!"<<endl<<endl;
      No_of_sixes=0;
      dice_number=0;
      return 0;
    }
  }
  return dice_number;
}
void find_where(int position[], string board [][15], string token ){
  string word;
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      word=board[i][j];
      if (word.length() <= 2){
        if (word[0] == token[0] && word[1]==token[1]) {
          position[0]=i;
          position[1]=j;
          return;
        }
        else{
          for (int k=0; k< word.length()/2; ++k){
            if (word[2*k] == token[0] && word[2*k+1]==token[1]) {
              position[0]=i;
              position[1]=j;
              return;
            }
          }
        }
      }
    }
  }
}

bool check_movable(){
  //will see and print which token is movable and will ask the user to input the token and will see if the move can take place. If yes, will ret
}

//before actually making a move, it will see if checkable by check_movable.
//
void make_a_move(string **player_name, int turn_count, int player_number, int No_of_sixes, int dice_number, string board[][15]){
  int position[2];
  string token;
  for (int i=0; i<No_of_sixes+1;++i){
    cout <<"which token would you like to move?"<<endl;
    cin >> token;
    //if (check_movable()){
    find_where (position, board, token);
      if (No_of_sixes!=0){
        if ((position[0] == 1 && position[1]==1) || (position[0]==1 && position[1]==3) || (position[0]==1 && position[1]==11) || (position[0]==1 && position[1]==13) || (position[0]==3 && position[1]==1) || (position[0]==3 && position[1]==3) || (position[0]==3 && position[1]==11) || (position[0]==3 && position[1]==13) || (position[0]==11 && position[1]==1) || (position[0]==11 && position[1]==3) || (position[0]==11 && position[1]==11) || (position[0]==11 && position[1]==13) || (position[0]==13 && position[1]==1) || (position[0]==13 && position[1]==3) || (position[0]==13 && position[1]==11) || (position[0]==13 && position[1]==13)){
          if (turn_count == 0){
            board[6][1] = token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
          else if(turn_count==1){
            board[8][13]=token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
          else if(turn_count == 2){
            board[13][6]=token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
          else if(turn_count == 3){
            board[1][8]=token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
        }
        else {
          for (int i=0; i<6; ++i){
            if (position[0]==6 || position[0]==0 ){
              if ((position[1]+1!=6) && (position[1]+1!=9) && (position[1]+1!=15)) {
                board[position[0]][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
              }
              else if(position[1]+1==6){
                board[position[0]-1][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
                position[0]--;
              }
              else if(position[1]+1==9){
                board[position[0]+1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]++;
              }
              else if(position[1]+1==15){
                board[position[0]+1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]--;
              }
            }

            else if (position[0]==8 || position[0]==14){
              if ((position[1]-1!=8) && (position[1]-1!=5) && (position[1]-1!=-1)) {
                board[position[0]][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
              }
              else if(position[1]-1==8){
                board[position[0]+1][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
                position[0]++;
              }
              else if(position[1]-1==5){
                board[position[0]-1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]--;
              }
              else if(position[1]-1==-1){
                board[position[0]-1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]++;
              }
            }

            else if (position[1]==6 || position[1]==0){
              if ((position[0]-1!=8) && (position[0]-1!=5) && (position[1]-1!=-1)) {
                board[position[0]-1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]--;
              }
              else if(position[0]-1==8){
                board[position[0]-1][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
                position[0]--;
              }
              else if(position[0]-1==5){
                board[position[0]][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
              }
              else if(position[1]-1==-1){
                board[position[0]][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
              }
            }

            else if (position[1]==8 || position[1]==14){
              if ((position[0]+1!=6) && (position[0]+1!=9) && (position[1]+1!=15)) {
                board[position[0]+1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]++;
              }
              else if(position[0]+1==6){
                board[position[0]+1][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
                position[0]++;
              }
              else if(position[0]+1==9){
                board[position[0]][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
              }
              else if(position[1]-1==15){
                board[position[0]][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;






          }

        }

            else if ( position[0] == 7){
          if ((position[1] == 1 || position[1] == 2 || position[1] == 3 || position[1] == 4 || position[1] == 5) && turn_count == 0) {
            position [1]++;
          }
          else if ((position[1] == 13 || position[1] == 12 || position[1] == 11 || position[1] == 10 || position[1] == 9 ) && turn_count == 1){
            position[1]--;
          }
        }

            else if ( position[1] == 7){
          if ( (position [0] == 1 || position[0] == 2 || position[0] == 3 || position[0] == 4 || position[0] == 5) && turn_count == 3){
            position[0]++;
          }
          else if ( (position[0] == 13 || position[0] == 12 || position[0] == 11 || position[0] == 10 || position[0] == 9) && turn_count == 2) {
            position[0]--;
          }
        }


            show_board(board);
          }
          show_board(board);
        }
        No_of_sixes--;
      }
      else if (No_of_sixes==0){
        for (int i=0; i<dice_number; ++i){
          if (position[0]==6 || position[0]==0){
            if ((position[1]+1!=6) && (position[1]+1!=9) && (position[1]+1!=15)) {
              board[position[0]][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
            }
            else if(position[1]+1==6){
              board[position[0]-1][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
              position[0]--;
            }
            else if(position[1]+1==9){
              board[position[0]+1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]++;
            }
            else if(position[1]+1==15){
              board[position[0]+1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]--;
            }
          }
          else if (position[0]==8 || position[0]==14){
            if ((position[1]-1!=8) && (position[1]-1!=5) && (position[1]-1!=-1)) {
              board[position[0]][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
            }
            else if(position[1]-1==8){
              board[position[0]+1][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
              position[0]++;
            }
            else if(position[1]-1==5){
              board[position[0]-1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]--;
            }
            else if(position[1]-1==-1){
              board[position[0]-1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]++;
            }
          }
          else if (position[1]==6 || position[1]==0){
            if ((position[0]-1!=8) && (position[0]-1!=5) && (position[1]-1!=-1)) {
              board[position[0]-1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]--;
            }
            else if(position[0]-1==8){
              board[position[0]-1][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
              position[0]--;
            }
            else if(position[0]-1==5){
              board[position[0]][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
            }
            else if(position[1]-1==-1){
              board[position[0]][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
            }
          }
          else if (position[1]==8 || position[1]==14){
            if ((position[0]+1!=6) && (position[0]+1!=9) && (position[1]+1!=15)) {
              board[position[0]+1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]++;
            }
            else if(position[0]+1==6){
              board[position[0]+1][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
              position[0]++;
            }
            else if(position[0]+1==9){
              board[position[0]][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
            }
            else if(position[1]-1==15){
              board[position[0]][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
            }
          }
          show_board(board);
        }
        dice_number=0;
      }
    //}
  }
}


int main(){
  int player_number, turn_count=0, dice_number=0, No_of_sixes = 0;
  string board[15][15];
  cout << "Please input number of players" << endl;
  cin >> player_number;
  while(player_number>4){
    cout << "Number of players cannot be greater than 4" << endl;
    cout << "Please input number of players again" << endl;
    cin >> player_number;
  }
  while(player_number<2){
    cout << "Number of players cannot be less than 2" << endl;
    cout << "Please input number of players again" << endl;
    cin >> player_number;
  }
  string** player_name = new string*[player_number];
  for(int i = 0; i < player_number; ++i){
    player_name[i] = new string[5];
  }

    for (int i = 0; i < player_number; ++i){
    cout << "Please input the name of " << i+1<<" player." << endl;
    cin >> player_name[i][0];
  }
  set_the_board(player_name, player_number, board);




  for (int i=0; i<10; ++i){
    if (turn_count == player_number){
      turn_count = 0;
    }
    cout << player_name[turn_count][0]<< "\'s turn" << endl;
    dice_number = roll_dice(player_name, turn_count, No_of_sixes, dice_number);
    if (dice_number != 0){
      cout << dice_number<< endl;
      make_a_move(player_name, turn_count, player_number, No_of_sixes, dice_number, board);
    }
    No_of_sixes=0;
    dice_number=0;
    turn_count++;
  }
}
