#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

// struct storing_board{
//   string arr[16];
// };

struct cordinates{
  int x;
  int y;
};

struct Profile{
  string username;
  int level;
  int xp;
  string token_symbols;
  int played;
  int won;
  string win_percentage;
};

struct Player_current_details{
  string username;    //
  char token;      //
  int player_number;
  string status;
  int rank;
};



/*Tells whether a particular token can be moved or not*/
bool can_move(string board[][15], int player_number, int dice_roll, int row_index, int col_index){
  bool can_be_moved;
  if((col_index < 6 && (row_index < 6 || row_index > 8)) || \ //in base or not
  (col_index > 8 && (row_index < 6 || row_index > 8))){
    if(dice_roll == 6){
      return 1;
    }
    else{
      return 0;
    }
  }
  can_be_moved = ! (col_index == 7 && (row_index == 6 || row_index == 8) || \ //has reached home or not
  row_index == 7 && (col_index == 6 || col_index == 8));
  int col_index2 = col_index, row_index2 = row_index;
  token_movement(player_number, dice_roll, row_index2, col_index2);
  return !(col_index == col_index2 && row_index == row_index2) && \
  can_be_moved; //else return 1
}

bool will_kill(string board[][15], int player_number, string token, int dice_roll, int row_index, int col_index){
    int col_index2 = col_index, row_index2 = row_index;
    bool land_at_home, land_at_star, not_on_empty, not_on_own_token, kills;
    token_movement(player_number, token, dice_roll, row_index2, col_index2);
    if(col_index2 == col_index && row_index2 == row_index){
      kills = 0;
    }
    else{
      land_at_star = ((col_index2 == 1 || col_index2 == 12) && row_index2 == 6 || \
        (col_index2 == 2 || col_index2 == 13) && row_index2 == 8 || \
        col_index2 == 6 && (row_index2 == 2 || row_index2 == 13) || \
        col_index2 == 8 && (row_index2 == 1 || row_index2 == 12));
      if(player_number == 1){
        land_at_home = (row_index2 == 7 && col_index2 > 0 && col_index2 <= 6);
        }
      else if(player_number == 4){
        land_at_home = (col_index2 == 7 && row_index2 > 0 && row_index2 <= 6);
      }
      else if(player_number == 2){
        land_at_home = (row_index2 == 7 && col_index2 >= 8 && col_index2 < 14);
      }
      else{
        land_at_home = (col_index2 == 7 && row_index2 >= 8 && row_index2 < 14)
      }
      not_on_empty = (board[row_index2][col_index2] != "xx" && board[row_index2][col_index2].length() == 2);
      not_on_own_token = board[row_index2][col_index2][0] != token[0];

      kills = (! land_at_star && ! land_at_home && not_on_empty && not_on_own_token);
    }
    if(kills == 1){
      return board[row_index2][col_index2];
    }
}

bool has_won(string board[][15], int player_number){
  if(player_number == 1){
    return board[7][6].length() == 8;
  }
  else if(player_number == 4){
    return board[6][7].length() == 8;
  }
  else if(player_number = 2){
    return board[7][8].length() == 8;
  }
  else{
    return board[8][7].length() == 8;
  }
}

void token_movement(int player_number, int dice_roll, int &row_index, int &col_index){
  int move1, move2, move3;
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
    else if(col_index > 8 && row_index == 6){//near player 3's home
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
    if(row_index < 6 && col_index == 8){ //near player2's home
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
    else if(row_index > 8 && col_index == 8){
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






// add 4 more stops.
void show_board(string board[][15]){
  int duplicate_places = 0;
  int stop = 0;
  char stop_or_not[8];
  cordinates arr[8]; //

  for (int i=0; i<15; ++i){
    for (int j=0; j<15; ++j){
      //write a condition to see if on stop
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

void set_the_board(current_player_details *player, int player_number, string board[][15]){
  char Color;
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
  for (int i = 0; i < player_number; ++i){
    char Color;
    if (i == 0){
      Color = 'R';
    }
    else if (i==1){
      Color = 'Y';
    }
    else if (i == 2){
      Color = 'B';
    }else {
      Color = 'G';
    }
    player[i].token[0]=Color + '1';
    player[i].token[1]=Color + '2';
    player[i].token[2]=Color + '3';
    player[i].token[3]=Color + '4';
    if (player_number == 2){
      cout << player[0].username<<" is Red(R)"<<endl;
      cout << player[1].username<<" is Yellow(Y)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[7][1]="RS";
      board[7][2]="RS";
      board[7][3]="RS";
      board[7][4]="RS";
      board[7][5]="RS";
      board[7][6]="RH";

      board[11][11]="Y1";
      board[11][13]="Y2";
      board[13][11]="Y3";
      board[13][13]="Y4";
      board[7][13]="YS";
      board[7][12]="YS";
      board[7][11]="YS";
      board[7][10]="YS";
      board[7][9]="YS";
      board[7][8]="YH";

      board[6][1]="SS";
      board[1][8]="SS";
      board[8][13]="SS";
      board[13][6]="SS";

    }
    else if (player_number == 3){
      cout << player[0].username<<" is Red(R)"<<endl;
      cout << player[1].username<<" is Yellow(Y)"<<endl;
      cout << player[2].username<<" is Blue(B)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[7][1]="RS";
      board[7][2]="RS";
      board[7][3]="RS";
      board[7][4]="RS";
      board[7][5]="RS";
      board[7][6]="RH";

      board[11][11]="Y1";
      board[11][13]="Y2";
      board[13][11]="Y3";
      board[33][13]="Y4";
      board[7][13]="YS";
      board[7][12]="YS";
      board[7][11]="YS";
      board[7][10]="YS";
      board[7][9]="YS";
      board[7][8]="YH";

      board[11][1]="B1";
      board[11][3]="B2";
      board[13][1]="B3";
      board[13][3]="B4";
      board[13][7]="BS";
      board[12][7]="BS";
      board[11][7]="BS";
      board[10][7]="BS";
      board[9][7]="BS";
      board[8][7]="BH";

      board[6][1]="SS";
      board[1][8]="SS";
      board[8][13]="SS";
      board[13][6]="SS";
    }
    else{
      cout << player[0].username<<" is Red(R)"<<endl;
      cout << player[1].username<<" is Yellow(Y)"<<endl;
      cout << player[2].username<<" is Blue(B)"<<endl;
      cout << player[3].username<<" is Green(G)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[7][1]="RS";
      board[7][2]="RS";
      board[7][3]="RS";
      board[7][4]="RS";
      board[7][5]="RS";
      board[7][6]="RH";

      board[11][11]="Y1";
      board[11][13]="Y2";
      board[13][11]="Y3";
      board[13][13]="Y4";
      board[7][13]="YS";
      board[7][12]="YS";
      board[7][11]="YS";
      board[7][10]="YS";
      board[7][9]="YS";
      board[7][8]="YH";

      board[11][1]="B1";
      board[11][3]="B2";
      board[13][1]="B3";
      board[13][3]="B4";
      board[13][7]="BS";
      board[12][7]="BS";
      board[11][7]="BS";
      board[10][7]="BS";
      board[9][7]="BS";
      board[8][7]="BH";

      board[1][11]="G1";
      board[1][13]="G2";
      board[3][11]="G3";
      board[3][13]="G4";
      board[1][7]="GS";
      board[2][7]="GS";
      board[3][7]="GS";
      board[4][7]="GS";
      board[5][7]="GS";
      board[6][7]="YH";


      board[6][1]="SS";
      board[1][8]="SS";
      board[8][13]="SS";
      board[13][6]="SS";
    }
    show_board(board);
  }
}

int roll_dice(current_details *player, int &turn_count, int & No_of_sixes, int &dice_number ){
  cout <<"Rolling the dice!"<<endl;
  srand(time(NULL));
  dice_number = rand()%6+1;
  if (dice_number == 6){
    cout << "6"<<endl<<endl;
    No_of_sixes++;
    if (No_of_sixes < 3){
      roll_dice(player, turn_count, No_of_sixes, dice_number);
    }
    if (No_of_sixes==3){
      cout<< player[turn_count].username << " lost his turn!"<<endl<<endl;
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

void replace_old_position(string board[][15], int row, int column, string token){
  if (board[row][column].length() > 2){   //if double token on previous place, so what will happen to previous location is
    for (int i=0; i< board[row][column].length(); ++i){
      if ( board[row][column][i] != token [0] && board[row][column][i+1] != token[1]){
        board[row][column].erase(i, 2);
        break;
      }

    }

  }
  else { //no double token on one place, so what will happen to previous location is

    if ( (row == 6 && column == 1) || ((row == 1 && column == 8)) || (row == 8 && column == 13) || (row == 13 && column == 6)){
      board[row][column] = "SS";
    }

    else if( row == 7 && ( column == 1 || column == 2 || column == 3 || column == 4 || column == 5)) {
      board[row][column] = "RS";
    }
    else if(row == 7 && ( column == 9 || column == 10 || column == 11 || column == 12 || column == 13)) {
      board[row][column] = "YS";
    }
    else if ( column == 7 && (row == 1 || row == 2 || row == 3 || row == 4 || row == 5)){
      board[row][column] = "GS";
    }
    else if ( column == 7 && (row == 9 || row == 10 || row == 11 || row == 12 || row == 13) ) {
      board[row][column] = "BS";
    }
    else if ( ((row  == 1 && column ==1) || (row ==1 && column ==3) || (row ==1 && column ==11) || (row ==1 && column ==13) || (row ==3 && column ==1) || (row ==3 && column ==3) || (row ==3 && column ==11) || (row ==3 && column ==13) || (row ==11 && column ==1) || (row ==11 && column ==3) || (row ==11 && column ==11) || (row ==11 && column ==13) || (row ==13 && column ==1) || (row ==13 && column ==3) || (row ==13 && column ==11) || (row ==13 && column ==13)) ) {
      board[row][column] = "  ";
    }
    else{
      board[row][column] = "XX";
    }
  }
}

void replace_new_position(string board[][15], int row, int column, string token, current_player_details *players) {
  string token2;
  if (board[row][column][1] == '1' || board[row][column][1] == '2' || board[row][column][1] == '3' || board[row][column][1] == '4'){   //if double token on previous place which I check by checking 2nd index of it, so what will happen to new location is
    token2=will_kill();
    if (token2.length() == 2) {
      for (i) //i<player_number
      if (players[i].token == token2[0]){
        //move to base
      }
      board[row][column] = token;
    }
    else{
      board[row][column] += token;
    } //R1R2Y3Y$
  else{
    board[row][column] = token;
  }
}


//before actually making a move, it will see if checkable by check_movable.
//
//Eg, RH will always show(only show while not store as RH if there is any token) as RH, and at the bottom of board it will display what tokens are there in RH, if there is.
//while
void make_a_move(current_player_details *player, int turn_count, int player_number, int No_of_sixes, int dice_number, string board[][15]){
  int position [2];
  string token;
  int old_position [2];
   //may be no need
  for (int i = 0; i < No_of_sixes+1 ; ++i) {          //three sixes, dice_number=0, No_of_sixes = 2, dice_number=5

    cout <<"which token would you like to move?"<<endl;
    cin >> token;
    //if (check_movable()){
    find_where (position, board, token);  //row=6, column =2
    old_position[0] = position[0];
    old_position[1] = position[1];

    if (No_of_sixes != 0){
      //if in their bases, then move that token out
      //store new position of the token
      if ((position[0] == 1 && position[1] == 1) || (position[0]==1 && position[1]==3) || (position[0]==1 && position[1]==11) || (position[0]==1 && position[1]==13) || (position[0]==3 && position[1]==1) || (position[0]==3 && position[1]==3) || (position[0]==3 && position[1]==11) || (position[0]==3 && position[1]==13) || (position[0]==11 && position[1]==1) || (position[0]==11 && position[1]==3) || (position[0]==11 && position[1]==11) || (position[0]==11 && position[1]==13) || (position[0]==13 && position[1]==1) || (position[0] == 13 && position[1]==3) || (position[0]==13 && position[1]==11) || (position[0]==13 && position[1]==13)){
        if (turn_count == 0){
          position[0] = 6;
          position[1] = 1;
        }
        else if(turn_count==1){
          position[0] = 8;
          position[1] = 13;
        }
        else if(turn_count == 2){
          position[0] = 13;
          position[1] = 6;
        }
        else if(turn_count == 3){
          position[0] = 1;
          position[1] = 8;
        }
      }

      //if not in bases and your number is six.
      //store new position of the token.

      else {
        token_movement(turn_count+1, 6, position[0], position[1] )   //will return modified in  position array
      }
    }

    else if (No_of_sixes == 0){
      token_movement(turn_count+1, dice_number, position[0], position[1] )
    }
    replace_old_position(board, old_position[0], old_position[1], token);
    replace_new_position(board, position[0], position[1], token);
    show_board(board);
    No_of_sixes--;
  }
}





int main(){
  int player_number;
  int turn_count=0;   //0 means 1st player
  int dice_number=0;
  int No_of_sixes = 0;
  cout << "Please input number of players" << endl;
  string board[15][15];
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

  current_player_details *player = new current_player_details[player_number];
  for (int i = 0; i < player_number; ++i){
    cout << "Please input the name of " << i+1<<" player." << endl;
    cin >> player[i].username;
  }

  show_board(board);
  set_the_board(player, player_number, board);



  for (int i=0; i<10; ++i){
    if (turn_count == player_number){
      turn_count = 0;
    }
    cout << player[turn_count].username<< "'s turn" << endl;
    dice_number = roll_dice(player, turn_count, No_of_sixes, dice_number);
    if (dice_number != 0){
      cout << dice_number<< endl;
      make_a_move(player, turn_count, player_number, No_of_sixes, dice_number, board);
    }
    No_of_sixes=0;
    dice_number=0;
    turn_count++;
  }

}
