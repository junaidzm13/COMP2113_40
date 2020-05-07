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

void replace_new_position(string board[][15], int row, int column, string token){
  if (board[row][column][1] == '1' || board[row][column][1] == '2' || board[row][column][1] == '3' || board[row][column][1] == '4'){   //if double token on previous place which I check by checking 2nd index of it, so what will happen to new location is
    board[row][column] += token;
    }
  else{
    board[row][column] = token;
  }
}


void make_a_move(player_details *player, int turn_count, int player_number, int No_of_sixes, int dice_number, string board[][15]){
  int position[2];
  string token;
  int old_position[2];
  int N=No_of_sixes;
  for (int i=0; i<N+1;++i){

    cout <<"which token would you like to move?"<<endl;
    cin >> token;
    //if (check_movable()){
    find_where (position, board, token);
    old_position[0]=position[0];
    old_position[1]=position[1];
    if (No_of_sixes!=0){

      //if in their bases, then move that token out
      //store new position of the token
      if ((position[0] == 1 && position[1] == 1) || (position[0]==1 && position[1]==3) || (position[0]==1 && position[1]==11) || (position[0]==1 && position[1]==13) || (position[0]==3 && position[1]==1) || (position[0]==3 && position[1]==3) || (position[0]==3 && position[1]==11) || (position[0]==3 && position[1]==13) || (position[0]==11 && position[1]==1) || (position[0]==11 && position[1]==3) || (position[0]==11 && position[1]==11) || (position[0]==11 && position[1]==13) || (position[0]==13 && position[1]==1) || (position[0]==13 && position[1]==3) || (position[0]==13 && position[1]==11) || (position[0]==13 && position[1]==13)){
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
        for (int i=0; i<6; ++i){


          if ((position[0] == 6) || (position[0] == 0)) {  // moving right
            if ((position[0] == 0 && position[1]+1 == 8)  && (turn_count == 3)){
              position[0]++;
            }
            else if ((position[1]+1!=6 && position[1]+1!=9) && position[1]+1!=15) {
              position[1]++;
            }
            else if(position[1]+1==6){
              position[1]++;
              position[0]--;
            }
            else if(position[1]+1==9){
              position[0]++;
            }
            else if(position[1]+1==15){
              position[0]--;
            }
          }

          else if ((position[0] == 8) || (position[0] == 14) ) {// moving left
            if ((position[0] == 14 && position[1]+1 == 6)  && (turn_count == 2)){
              position[0]--;
            }
            else if ((position[1]-1!=8 && position[1]-1!=5) && (position[1]-1!=-1)) {
              position[1]--;
            }
            else if(position[1]-1==8){
              position[1]--;
              position[0]++;
            }
            else if(position[1]-1==5){
              position[0]--;
            }
            else if(position[1]-1==-1){
              position[0]++;
            }
          }

          else if ((position[1]==6) || (position[1]==0) ) { // moving up
            if ((position[0] - 1 == 6 && position[1] == 0)  && (turn_count == 0)) {
              position[1]++;
            }
            else if ((position[0]-1!=8 && position[0]-1!=5) && (position[1]-1!=-1)) {
              position[0]--;
            }
            else if(position[0]-1==8){
              position[1]--;
              position[0]--;
            }
            else if(position[0]-1==5){
              position[1]++;
            }
            else if(position[1]-1==-1){
              position[1]++;
            }
          }

          else if ((position[1]==8) || (position[1]==14)) {// moving down
            if ((position[0] + 1 == 8 && position[1] == 14)  && (turn_count == 1)){
              position[1]--;
            }
            else if ((position[0]+1!=6 && position[0]+1!=9) && (position[1]+1!=15)) {
              position[0]++;
            }
            else if(position[0]+1==6){
              position[1]++;
              position[0]++;
            }
            else if(position[0]+1==9){
              position[1]--;
            }
            else if(position[1]-1==15){
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
        }
      }

      //if (board[old_position[0]][old_position[1]].length() <= 2){

    }

    else if (No_of_sixes == 0){

      for (int i=0; i <  dice_number; ++i){


        if ((position[0] == 6) || (position[0] == 0)) {  // moving right
          if ((position[0] == 0 && position[1]+1 == 8)  && (turn_count == 3)){
            position[0]++;
          }
          else if ((position[1]+1!=6 && position[1]+1!=9) && position[1]+1!=15) {
            position[1]++;
          }
          else if(position[1]+1==6){
            position[1]++;
            position[0]--;
          }
          else if(position[1]+1==9){
            position[0]++;
          }
          else if(position[1]+1==15){
            position[0]--;
          }
        }

        else if ((position[0] == 8) || (position[0] == 14) ) {// moving left
          if ((position[0] == 14 && position[1]+1 == 6)  && (turn_count == 2)){
            position[0]--;
          }
          else if ((position[1]-1!=8 && position[1]-1!=5) && (position[1]-1!=-1)) {
            position[1]--;
          }
          else if(position[1]-1==8){
            position[1]--;
            position[0]++;
          }
          else if(position[1]-1==5){
            position[0]--;
          }
          else if(position[1]-1==-1){
            position[0]++;
          }
        }

        else if ((position[1]==6) || (position[1]==0) ) { // moving up
          if ((position[0] - 1 == 6 && position[1] == 0)  && (turn_count == 0)) {
            position[1]++;
          }
          else if ((position[0]-1!=8 && position[0]-1!=5) && (position[1]-1!=-1)) {
            position[0]--;
          }
          else if(position[0]-1==8){
            position[1]--;
            position[0]--;
          }
          else if(position[0]-1==5){
            position[1]++;
          }
          else if(position[1]-1==-1){
            position[1]++;
          }
        }

        else if ((position[1]==8) || (position[1]==14)) {// moving down
          if ((position[0] + 1 == 8 && position[1] == 14)  && (turn_count == 1)){
            position[1]--;
          }
          else if ((position[0]+1!=6 && position[0]+1!=9) && (position[1]+1!=15)) {
            position[0]++;
          }
          else if(position[0]+1==6){
            position[1]++;
            position[0]++;
          }
          else if(position[0]+1==9){
            position[1]--;
          }
          else if(position[1]-1==15){
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
    }

    replace_old_position(board, old_position[0], old_position[1], token);
    replace_new_position(board, position[0], position[1], token);
    show_board(board);
    No_of_sixes--;
  }

}
