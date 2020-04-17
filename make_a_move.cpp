void make_a_move(string **player_name, int turn_count, int player_number, int No_of_sixes, int dice_number, string board[][15]){
  int position[2];
  string token;
  for (int i=0; i<No_of_sixes+1;++i){
    cout <<"which token would you like to move?"<<endl;
    cin >> token;
    //if (check_movable()){
    find_where (position, board, token);
      if (No_of_sixes!=0){
        if ((position[0] == 1 && position[1]==1) || (position[0]==1 && position[1]==3) || (position[0]==1 && position[1]==11) || (position[0]==1 && position[1]==13) || (position[0]==3 && position[1]==1) || (position[0]==3 && position[1]==3) || (position[0]==3 && position[1]==11) || (position[0]==3 && position[1]==13) || (position[0]==11 && position[1]==1) || (position[0]==11 && position[1]==3) || (position[0]==11 && position[1]==11) || (position[0]==11 && position[1]==13) || (position[0]==13 && position[1]==1) || (position[0]==13 && position[1]==3) || (position[0]==13 && position[1]==11) || (position[0]==13 && position[1]==13)){
          if (turn_count == 0){
            board[6][1] = token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
          else if(turn_count==1){
            board[8][13]=token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
          else if(turn_count == 2){
            board[13][6]=token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
          else if(turn_count == 3){
            board[1][8]=token;
            board[position[0]][position[1]] = "  ";
            show_board(board);
          }
        }
        else {
          for (int i=0; i<6; ++i){
            if (position[0]==6 || position[0]==0){
              if ((position[1]+1!=6) && (position[1]+1!=9) && (position[1]+1!=15)) {
                board[position[0]][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
              }
              else if(position[1]+1==6){
                board[position[0]-1][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
                position[0]--;
              }
              else if(position[1]+1==9){
                board[position[0]+1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]++;
              }
              else if(position[1]+1==15){
                board[position[0]+1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]--;
              }
            }
            else if (position[0]==8 || position[0]==14){
              if ((position[1]-1!=8) && (position[1]-1!=5) && (position[1]-1!=-1)) {
                board[position[0]][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
              }
              else if(position[1]-1==8){
                board[position[0]+1][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
                position[0]++;
              }
              else if(position[1]-1==5){
                board[position[0]-1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]--;
              }
              else if(position[1]-1==-1){
                board[position[0]-1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]++;
              }
            }
            else if (position[1]==6 || position[1]==0){
              if ((position[0]-1!=8) && (position[0]-1!=5) && (position[1]-1!=-1)) {
                board[position[0]-1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]--;
              }
              else if(position[0]-1==8){
                board[position[0]-1][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
                position[0]--;
              }
              else if(position[0]-1==5){
                board[position[0]][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
              }
              else if(position[1]-1==-1){
                board[position[0]][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
              }
            }
            else if (position[1]==8 || position[1]==14){
              if ((position[0]+1!=6) && (position[0]+1!=9) && (position[1]+1!=15)) {
                board[position[0]+1][position[1]]=token;
                board[position[0]][position[1]]="XX";
                position[0]++;
              }
              else if(position[0]+1==6){
                board[position[0]+1][position[1]+1]=token;
                board[position[0]][position[1]]="XX";
                position[1]++;
                position[0]++;
              }
              else if(position[0]+1==9){
                board[position[0]][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;
              }
              else if(position[1]-1==15){
                board[position[0]][position[1]-1]=token;
                board[position[0]][position[1]]="XX";
                position[1]--;






          }

        }
            show_board(board);
          }
          show_board(board);
        }
        No_of_sixes--;
      }
      else if (No_of_sixes==0){
        for (int i=0; i<dice_number; ++i){
          if (position[0]==6 || position[0]==0){
            if ((position[1]+1!=6) && (position[1]+1!=9) && (position[1]+1!=15)) {
              board[position[0]][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
            }
            else if(position[1]+1==6){
              board[position[0]-1][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
              position[0]--;
            }
            else if(position[1]+1==9){
              board[position[0]+1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]++;
            }
            else if(position[1]+1==15){
              board[position[0]+1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]--;
            }
          }
          else if (position[0]==8 || position[0]==14){
            if ((position[1]-1!=8) && (position[1]-1!=5) && (position[1]-1!=-1)) {
              board[position[0]][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
            }
            else if(position[1]-1==8){
              board[position[0]+1][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
              position[0]++;
            }
            else if(position[1]-1==5){
              board[position[0]-1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]--;
            }
            else if(position[1]-1==-1){
              board[position[0]-1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]++;
            }
          }
          else if (position[1]==6 || position[1]==0){
            if ((position[0]-1!=8) && (position[0]-1!=5) && (position[1]-1!=-1)) {
              board[position[0]-1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]--;
            }
            else if(position[0]-1==8){
              board[position[0]-1][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
              position[0]--;
            }
            else if(position[0]-1==5){
              board[position[0]][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
            }
            else if(position[1]-1==-1){
              board[position[0]][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
            }
          }
          else if (position[1]==8 || position[1]==14){
            if ((position[0]+1!=6) && (position[0]+1!=9) && (position[1]+1!=15)) {
              board[position[0]+1][position[1]]=token;
              board[position[0]][position[1]]="XX";
              position[0]++;
            }
            else if(position[0]+1==6){
              board[position[0]+1][position[1]+1]=token;
              board[position[0]][position[1]]="XX";
              position[1]++;
              position[0]++;
            }
            else if(position[0]+1==9){
              board[position[0]][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
            }
            else if(position[1]-1==15){
              board[position[0]][position[1]-1]=token;
              board[position[0]][position[1]]="XX";
              position[1]--;
            }
          }
          show_board(board);
        }
        dice_number=0;
      }
    //}
  }
}
