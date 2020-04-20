void linear_search(int position[], string board [][15], string token ){
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
