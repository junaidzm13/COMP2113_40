void set_the_board(player_details *player, int player_number, string board[][15]){
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
