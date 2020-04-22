
void replace_new_position(string board[][15], int row, int column, string token){
  if (board[row][column][1] == '1' || board[row][column][1] == '2' || board[row][column][1] == '3' || board[row][column][1] == '4'){   //if double token on previous place which I check by checking 2nd index of it, so what will happen to new location is
    board[row][column] += token;
    }
  else{
    board[row][column] = token;
  }
}
