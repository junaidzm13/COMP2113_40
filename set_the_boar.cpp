void set_the_board(string *player_name, int player_number, string board[][15]){
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
    if (player_number == 2){
      cout << player_name[i]<<" is Red(R)"<<endl;
      cout << player_name[i]<<" is Green(G))"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[11][11]="G1";
      board[11][13]="G2";
      board[13][11]="G3";
      board[13][13]="G4";
    }
    else if (player_number == 3){
      cout << player_name[i]<<" is Red(R)"<<endl;
      cout << player_name[i]<<" is Yellow(Y)"<<endl;
      cout << player_name[i]<<" is Blue(B)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[1][11]="Y1";
      board[1][13]="Y2";
      board[3][11]="Y3";
      board[3][13]="Y4";
      board[11][1]="B1";
      board[11][3]="B2";
      board[13][1]="B3";
      board[13][3]="B4";
    }
    else{
      cout << player_name[i]<<" is Red(R)"<<endl;
      cout << player_name[i]<<" is Yellow(Y)"<<endl;
      cout << player_name[i]<<" is Blue(B)"<<endl;
      cout << player_name[i]<<" is Green(G)"<<endl;
      board[1][1]="R1";
      board[1][3]="R2";
      board[3][1]="R3";
      board[3][3]="R4";
      board[1][11]="Y1";
      board[1][13]="Y2";
      board[3][11]="Y3";
      board[3][13]="Y4";
      board[11][1]="B1";
      board[11][3]="B2";
      board[13][1]="B3";
      board[13][3]="B4";
      board[11][11]="G1";
      board[11][13]="G2";
      board[13][11]="G3";
      board[13][13]="G4";
    }
    for (int i=0; i<15; ++i){
      for (int j=0; j<15;++j){
        cout << board[i][j]<<" ";
      }
      cout <<endl;
    }
  }
}
