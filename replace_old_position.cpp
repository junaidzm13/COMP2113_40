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
