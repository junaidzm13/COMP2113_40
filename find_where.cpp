void find_where(int position[], string board [][15], string token ){
  string word;
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      word=board[i][j];
      if (word[0]==token[0] && word[1]==token[1]) {
        position[0]=i;
        position[1]=j;
        return;
      }
    }
  }
}
