void show_board(string board[][15]){
  for (int i=0; i<15; ++i){
    for (int j=0; j<15;++j){
      cout << board[i][j]<<" ";
    }
    cout <<endl;
  }
  cout<<endl<<endl;
}
