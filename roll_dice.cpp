int roll_dice(string *player_name, int &turn_count, int &No_of_sixes ){
  int dice_number;
  cout <<player_name[turn_count]<<"\'s turn"<<endl;
  srand(time(NULL));
  dice_number = rand()%6+1;
  if (dice_number == 6){
    No_of_sixes++;
    if (No_of_sixes < 3){
      roll_dice(player_name, turn_count, player_number, No_of_sixes);
    }
    if (No_of_sixes==3){
      return 0;
    }
  }
  return dice_number;
}
