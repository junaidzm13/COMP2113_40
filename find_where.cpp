void linear_search(string board [][15], string target, int indexes[]){
  for(int i = 0; i < 15; ++i){
    for(int j = 0; j < 15; ++j){
      if (board[i][j] == target) {
        indexes[0] = i;
        indexes[1] = j;
        return;
      }
    }
  }
  indexes[0] = -1;
  indexes[1] = -1;
  return;
}
