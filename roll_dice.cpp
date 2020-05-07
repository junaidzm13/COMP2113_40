int roll_dice(player_details *player, int &turn_count, int & No_of_sixes, int &dice_number ){
  cout <<"Rolling the dice!"<<endl;
  srand(time(NULL));
  dice_number = rand()%6+1;
  if (dice_number == 6){
    cout << "6"<<endl<<endl;
    No_of_sixes++;
    if (No_of_sixes < 3){
      roll_dice(player, turn_count, No_of_sixes, dice_number);
    }
    if (No_of_sixes==3){
      cout<< player[turn_count].username << " lost his turn!"<<endl<<endl;
      No_of_sixes=0;
      dice_number=0;
      return 0;
    }
  }
  return dice_number;
}
